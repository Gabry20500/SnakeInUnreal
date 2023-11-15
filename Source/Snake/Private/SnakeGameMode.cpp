// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeGameMode.h"
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
		UE_LOG(LogTemp, Display, TEXT("In World"));
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
}

void ASnakeGameMode::SpawnWallAtLocation(UWorld* World, FVector SpawnLocation, FRotator SpawnRotation)
{
	if (World && WallMesh)
	{
		FActorSpawnParameters SpawnParams;
		AStaticMeshActor* NewWall = World->SpawnActor<AStaticMeshActor>(WallMesh, SpawnLocation, SpawnRotation, SpawnParams);

		/*if (NewWall)
		{
			UStaticMeshComponent* WallStaticMeshComponent = NewWall->GetStaticMeshComponent();
			UStaticMesh* StaticMesh = WallMesh->GetDefaultObject<UStaticMeshComponent>()->GetStaticMesh();

			if (WallStaticMeshComponent && StaticMesh)
			{
				WallStaticMeshComponent->SetStaticMesh(StaticMesh);
				NewWall->SetActorScale3D(FVector(1.0f));
			}
		}*/
	}
}
