// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeGameMode.h"

#include "SnakePawn.h"
#include "SnakePlayerController.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"

ASnakeGameMode::ASnakeGameMode()
{
	static ConstructorHelpers::FClassFinder<AStaticMeshActor> WallMeshAsset(TEXT("/Game/Wall/WallAsset"));
	if (WallMeshAsset.Succeeded())
	{
		WallMesh = WallMeshAsset.Class;
	}

	DefaultPawnClass = ASnakePawn::StaticClass();
	PlayerControllerClass = ASnakePlayerController::StaticClass();
}

void ASnakeGameMode::BeginPlay()
{
	Super::BeginPlay();
	CreateGameGrid();
}

void ASnakeGameMode::CreateGameGrid()
{
	UWorld* World = GetWorld();
	FRotator Rotation = FRotator(0.0f, 90.0f, 0.0f);

	if (World) 
	{
		FVector StartLocation = FVector(0.0f, 0.0f, 0.0f);

		for (int32 i = 0; i < GridHeight; i++) {
			SpawnWallAtLocation(World, StartLocation + FVector(0.0f, i * WallSize, 0.0f), FRotator::ZeroRotator);
			SpawnWallAtLocation(World, StartLocation + FVector((GridWidth - 1) * WallSize, i * WallSize, 0.0f), FRotator::ZeroRotator);
		}

		for (int32 i = 0; i < GridWidth; ++i)
		{
			SpawnWallAtLocation(World, StartLocation + FVector(i * WallSize, 0.0f, 0.0f), Rotation);
			SpawnWallAtLocation(World, StartLocation + FVector(i * WallSize, (GridHeight - 1) * WallSize, 0.0f), Rotation);
		}
	}

	float MaxGridSize = FMath::Max(GridWidth * WallSize, GridHeight * WallSize);
	float CameraDistance = MaxGridSize / (2.0f * FMath::Tan(FMath::DegreesToRadians(60.0f)));
	FVector CenterLocation = FVector((GridWidth - 1) * WallSize * 0.5f, (GridHeight - 1) * WallSize * 0.5f, CameraDistance);
	
	SpawnCameraAtLocation(World, CenterLocation);
}

void ASnakeGameMode::SpawnCameraAtLocation(UWorld* World, FVector SpawnLocation)
{
	if (World)
	{
		UClass* CameraBlueprintClass = LoadClass<AActor>(nullptr, TEXT("/Game/BP_Camera.BP_Camera_C"));
		if (CameraBlueprintClass)
		{
			FActorSpawnParameters SpawnParams;
			AActor* NewCamera = World->SpawnActor<AActor>(CameraBlueprintClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
			if (NewCamera)
			{
				// Imposta la telecamera come telecamera attiva
				APlayerController* PlayerController = World->GetFirstPlayerController();
				if (PlayerController)
				{
					PlayerController->SetViewTarget(NewCamera);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Impossibile caricare il blueprint della telecamera."));
		}
	}
}

void ASnakeGameMode::SpawnWallAtLocation(UWorld* World, FVector SpawnLocation, FRotator SpawnRotation)
{
	if (World && WallMesh)
	{
		FActorSpawnParameters SpawnParams;
		AStaticMeshActor* NewWall = World->SpawnActor<AStaticMeshActor>(WallMesh, SpawnLocation, SpawnRotation, SpawnParams);
	}
}
