// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SnakePawn.generated.h"

UCLASS()
class SNAKE_API ASnakePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakePawn();
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	void AddSegment();

	float GetSegmentLength() const { return SegmentLength; }
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<class ASnakeSegment> SegmentClass;

	TArray<ASnakeSegment*> SnakeSegments;
	int32 SnakeLength;
	float SegmentLength;
	FVector MoveDirection;
};
