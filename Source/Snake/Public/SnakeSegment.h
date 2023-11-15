// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeSegment.generated.h"

UCLASS()
class SNAKE_API ASnakeSegment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeSegment();

	virtual void Tick(float DeltaTime) override;

	void MoveSegment(const FVector& NewLocation, const FRotator& NewRotation);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	UStaticMeshComponent* SegmentMesh;
};
