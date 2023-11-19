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

	static ConstructorHelpers::FClassFinder<ASnakeSegment> SegmentClassFInder(TEXT("/Game/Snake/BP_SnakeSegment.BP_SnakeSegment"));
	if (SegmentClassFInder.Succeeded())
	{
		SegmentClass = SegmentClassFInder.Class;
	}

}

void ASnakePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
}

// Called to bind functionality to input
void ASnakePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
