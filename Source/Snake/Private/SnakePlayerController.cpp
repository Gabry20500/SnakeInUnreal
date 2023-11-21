// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePlayerController.h"
#include "SnakePawn.h"

ASnakePlayerController::ASnakePlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASnakePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ASnakePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASnakePlayerController::MoveRight);

}

void ASnakePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetPawn())
	{
		if (auto Snake = Cast<ASnakePawn>(GetPawn()))
		{
			Snake->UpdateSegmentsPositions();
		}

		// Movimento automatico in avanti
		FVector NewLocation = GetPawn()->GetActorLocation() + (CurrentDirection * DeltaSeconds * MovementSpeed);
		GetPawn()->SetActorLocation(NewLocation);
		GetPawn()->SetActorRotation(FQuat::Slerp(GetPawn()->GetActorRotation().Quaternion(), CurrentDirection.ToOrientationQuat(), DeltaSeconds * 10.0f));
	}
}

void ASnakePlayerController::BeginPlay()
{
	Super::BeginPlay();

	CurrentDirection = FVector::ForwardVector;
	CurrentDirectionEnum = Direction::Foreward;
	MovementSpeed = 500.0f; 
}

void ASnakePlayerController::MoveForward(float AxisValue)
{
	if (AxisValue != 0.0f)
	{
		if (AxisValue > 0.0f && CurrentDirectionEnum != Direction::Backard)
		{
			// Muoviti verso destra
			CurrentDirection = FVector::ForwardVector; // ForwardVector rappresenta la direzione in avanti
			GetPawn()->SetActorRotation(FQuat::Slerp(GetPawn()->GetActorRotation().Quaternion(), CurrentDirection.ToOrientationQuat(), GetWorld()->GetDeltaSeconds() * 10.0f));
			CurrentDirectionEnum = Direction::Foreward;
		}
		else if (AxisValue < 0.0f && CurrentDirectionEnum != Direction::Foreward)
		{
			// Muoviti verso sinistra
			CurrentDirection = -FVector::ForwardVector; // Inverti la direzione in avanti per muoverti a sinistra
			GetPawn()->SetActorRotation(FQuat::Slerp(GetPawn()->GetActorRotation().Quaternion(), CurrentDirection.ToOrientationQuat(), GetWorld()->GetDeltaSeconds() * 10.0f));
			CurrentDirectionEnum = Direction::Backard;
		}
	}
}

void ASnakePlayerController::MoveRight(float AxisValue)
{
	if (AxisValue != 0.0f)
	{
		if (AxisValue > 0.0f && CurrentDirectionEnum != Direction::Left)
		{
			// Muoviti verso destra
			CurrentDirection = FVector::RightVector; // ForwardVector rappresenta la direzione in avanti
			GetPawn()->SetActorRotation(FQuat::Slerp(GetPawn()->GetActorRotation().Quaternion(), CurrentDirection.ToOrientationQuat(), GetWorld()->GetDeltaSeconds() * 10.0f));
			CurrentDirectionEnum = Direction::Right;
		}
		else if (AxisValue < 0.0f && CurrentDirectionEnum != Direction::Right)
		{
			// Muoviti verso sinistra
			CurrentDirection = -FVector::RightVector; // Inverti la direzione in avanti per muoverti a sinistra
			GetPawn()->SetActorRotation(FQuat::Slerp(GetPawn()->GetActorRotation().Quaternion(), CurrentDirection.ToOrientationQuat(), GetWorld()->GetDeltaSeconds() * 10.0f));
			CurrentDirectionEnum = Direction::Left;
		}
	}
}

