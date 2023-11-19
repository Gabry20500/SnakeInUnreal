// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SnakePlayerController.generated.h"

UENUM()
enum Direction
{
	Foreward,
	Backard,
	Left,
	Right
};

/**
 * 
 */
UCLASS()
class SNAKE_API ASnakePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASnakePlayerController();

	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	bool bStartedMoving;
	FVector CurrentDirection;
	float MovementSpeed;
	FVector MovementInput;
	float Time;

	Direction CurrentDirectionEnum;
};
