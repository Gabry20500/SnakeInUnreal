// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeSegment.h"

// Sets default values
ASnakeSegment::ASnakeSegment()
{
 	SegmentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SegmentMesh"));
	RootComponent = SegmentMesh;

}

// Called every frame
void ASnakeSegment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASnakeSegment::MoveSegment(const FVector& NewLocation, const FRotator& NewRotation)
{
	SetActorLocationAndRotation(NewLocation, NewRotation);
}

