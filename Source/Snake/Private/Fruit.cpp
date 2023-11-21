// Fill out your copyright notice in the Description page of Project Settings.


#include "Fruit.h"
#include "SnakePawn.h"
#include "SnakeGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFruit::AFruit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FruitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FruitMesh"));
	RootComponent = FruitMesh;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FruitMeshAsset(TEXT("/Game/Food_Pack_01/Meshes/Food_Fruit_Watermelon_01.Food_Fruit_Watermelon_01"));
	if (FruitMeshAsset.Succeeded())
	{
		FruitMesh->SetStaticMesh(FruitMeshAsset.Object);
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("Impossibile caricare il blueprint della frutta."));
	}

	ASnakeGameMode* GameMode = Cast<ASnakeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		 Width = GameMode->GridWidth;
		 Height = GameMode->GridHeight;
		 WallSize = GameMode->WallSize;
	}
	SnakePawnClass = ASnakePawn::StaticClass();
	SnakePawnInstance = nullptr;
}

// Called when the game starts or when spawned
void AFruit::BeginPlay()
{
	Super::BeginPlay();
	SnakePawnInstance = Cast<ASnakePawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (SnakePawnInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Serpente spawnato."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Problemi con il pawn del serpente."));
	}
	SpawnFruit();
}

// Called every frame
void AFruit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CeckCollision();
}

void AFruit::Consume()
{
	if(SnakePawnInstance)
	{
		SnakePawnInstance->AddSegment();

		SpawnFruit();
	}
}

void AFruit::SpawnFruit()
{
	UWorld* World = GetWorld();
	if (World)
	{
		FVector RandomLocation = FVector(FMath::RandRange(1,  Width - 2) * WallSize,
			FMath::RandRange(1, Height - 2) * WallSize,
			100.0f);

		SetActorLocation(RandomLocation); // Imposta la posizione del frutto
	}
}

void AFruit::CeckCollision()
{
	if (SnakePawnInstance)
	{
		float Distance = FVector::Distance(GetActorLocation(), SnakePawnInstance->GetActorLocation());

		// Controlla se la testa del serpente è abbastanza vicina da consumare il frutto
		if (Distance <  200.0f)
		{
			Consume();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Problemi con le collisionio."));
	}
}

