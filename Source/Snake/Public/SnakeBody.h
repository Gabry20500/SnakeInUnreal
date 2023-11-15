// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnakeSegment.h"
#include "GameFramework/Pawn.h"
#include "SnakeBody.generated.h"

UCLASS()
class SNAKE_API ASnakeBody : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakeBody();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveSnake();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TArray<ASnakeSegment*> SnakeSegments;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	FRotator InitialRotation;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	FVector InitialLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<ASnakeSegment> SegmentClass;

	void CreateInitialSnake();

	void MoveForward(float axisvalue);

	void MoveRight(float axisvalue);


};
