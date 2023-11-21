// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePawn.h"
#include "SnakeSegment.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ASnakePawn::ASnakePawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SnakeLength = 1;
	SegmentLength = 100.0f;
	MoveDirection = FVector::ForwardVector;


	static ConstructorHelpers::FClassFinder<ASnakeSegment> SegmentClassFinder(TEXT("/Game/Snake/BP_SnakeSegment.Bp_SnakeSegment"));
	if (SegmentClassFinder.Succeeded())
	{
		SegmentClass = SegmentClassFinder.Class;
		if (SegmentClass)
		{
			UE_LOG(LogTemp, Warning, TEXT("Classe SnakeSegment caricata correttamente"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Classe SnakeSegment non trovata"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Classe BP_SnakeSegment non trovata"));
	}
}

void ASnakePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (skipMovement) 
	{
		skipMovement = false;
		return;
	}
	
	//UpdateSegmentsPositions();
}

void ASnakePawn::BeginPlay()
{
	Super::BeginPlay();

	/*if (SegmentClass)
	{
		FVector NewLocation = GetActorLocation() - MoveDirection * SegmentLength;
		FRotator NewRotation = GetActorRotation();

		ASnakeSegment* NewSegment = GetWorld()->SpawnActor<ASnakeSegment>(SegmentClass, NewLocation, NewRotation);
		if (NewSegment)
		{
			SnakeSegments.Add(NewSegment);
		}
	}*/
}

void ASnakePawn::AddSegment()
{
	if(SegmentClass)
	{
		FTransform TailTransform = SnakeSegments.Num() > 0 ? SnakeSegments[SnakeSegments.Num() - 1]->GetTransform() : GetTransform();
		
		FVector NewLocation = TailTransform.GetLocation() - UKismetMathLibrary::GetForwardVector(TailTransform.Rotator()) * -SegmentLength;
		FRotator NewRotation = TailTransform.Rotator();
		
		
		ASnakeSegment* NewSegment = GetWorld()->SpawnActor<ASnakeSegment>(SegmentClass, NewLocation, NewRotation);
		if(NewSegment)
		{
			skipMovement = true;
			SnakeSegments.Add(NewSegment);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Impossibile creare segmento"));
	}
}

// Called to bind functionality to input
void ASnakePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASnakePawn::UpdateSegmentsPositions()
{
	if (SnakeSegments.Num() > 0)
	{
		FVector PreviusLocation = GetActorLocation() - UKismetMathLibrary::GetForwardVector(GetActorTransform().Rotator()) * SegmentLength;
		
		for (int32 i = SnakeSegments.Num()-1; i > 0 ; i--)
		{
			FVector CurrentLocation = SnakeSegments[i - 1]->GetActorLocation();
			SnakeSegments[i]->MoveSegment(CurrentLocation, SnakeSegments[i - 1]->GetActorRotation());
		}

		SnakeSegments[0]->MoveSegment(PreviusLocation, GetActorRotation());
	}
}
