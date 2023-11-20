// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnakeGameMode.h"
#include "GameFramework/Actor.h"
#include "Fruit.generated.h"

UCLASS()
class SNAKE_API AFruit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFruit();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Consume();
public:	
	void SpawnFruit();
	UFUNCTION()
	void CeckCollision();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* FruitMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent ;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Snake", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ASnakePawn> SnakePawnClass;
	
	UPROPERTY()
	class ASnakePawn* SnakePawnInstance;

	int32 Width;
	int32 Height;
	float WallSize;
};
