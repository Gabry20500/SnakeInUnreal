// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SNAKE_API ASnakeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASnakeGameMode();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SnakeGame")
	int32 GridWidth = 30;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SnakeGame")
	int32 GridHeight = 30;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SnakeGame")
	float WallSize= 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "SnakeGame")
	TSubclassOf<AActor> WallMesh;

	void CreateGameGrid();
	void SpawnWallAtLocation(UWorld* World, FVector SpawnLocation, FRotator SpawnRotation);
};
