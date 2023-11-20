// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePawn.h"
#include "SnakeSegment.h"

// Sets default values
ASnakePawn::ASnakePawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SnakeLength = 1;
	SegmentLength = 100.0f;
	MoveDirection = FVector::ForwardVector;

	static ConstructorHelpers::FClassFinder<ASnakeSegment> SegmentClassFinder(TEXT("/Game/Snake/Bp_SnakeSegment.Bp_SnakeSegment"));
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

	if (SegmentClass)
	{
		FVector NewLocation = GetActorLocation() - MoveDirection * SegmentLength;
		FRotator NewRotation = GetActorRotation();

		ASnakeSegment* NewSegment = GetWorld()->SpawnActor<ASnakeSegment>(SegmentClass, NewLocation, NewRotation);
		if (NewSegment)
		{
			SnakeSegments.Add(NewSegment);
		}
	}
}

void ASnakePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASnakePawn::BeginPlay()
{
	Super::BeginPlay();
}

void ASnakePawn::AddSegment()
{
	if(SegmentClass)
	{
		FVector NewLocation = SnakeSegments.Last() ? SnakeSegments.Last()->GetActorLocation()  - MoveDirection * SegmentLength : GetActorLocation();
		FRotator NewRotation = SnakeSegments.Last() ? SnakeSegments.Last()->GetActorRotation() : GetActorRotation();
		
		ASnakeSegment* NewSegment = GetWorld()->SpawnActor<ASnakeSegment>(SegmentClass, NewLocation, NewRotation);
		if(NewSegment)
		{
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
