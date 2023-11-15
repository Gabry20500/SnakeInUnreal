// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBody.h"
#include "GameFramework/FloatingPawnMovement.h" // Aggiunto per il movimento del Pawn

ASnakeBody::ASnakeBody()()
{
    SegmentSpacing = 100.0f;
    InitialRotation = FRotator::ZeroRotator;
    InitialLocation = FVector::ZeroVector;
    SegmentClass = ASnakeSegment::StaticClass();

    CreateInitialSnake();

    // Aggiungi il componente di movimento al Pawn
    UFloatingPawnMovement* MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
    if (MovementComponent)
    {
        MovementComponent->MaxSpeed = 500.0f; // Imposta la velocità massima di movimento
        SetRootComponent(MovementComponent);
    }
}

void ASnakeBody::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Implementa qui la logica per il tick del serpente
    MoveSnake(); // Chiamata alla funzione per il movimento del serpente durante ogni tick
}

void ASnakeBody::MoveSnake()
{
    // Implementa qui la logica per il movimento del serpente
    // Utilizza i comandi di movimento del Pawn se necessario
    // Esempio: AddMovementInput(GetActorForwardVector(), AxisValue);
}

void ASnakeBody::CreateInitialSnake()
{
    for (int32 i = 0; i < 3; ++i) // Creiamo inizialmente 3 segmenti per il serpente
    {
        FVector NewLocation = InitialLocation + FVector(SegmentSpacing * i, 0.0f, 0.0f);
        ASnakeSegment* NewSegment = GetWorld()->SpawnActor<ASnakeSegment>(SegmentClass, NewLocation, InitialRotation);

        if (NewSegment)
        {
            SnakeSegments.Add(NewSegment);
        }
    }
}

void ASnakeBody::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Associare le funzioni di input ai comandi del giocatore
    PlayerInputComponent->BindAxis("MoveForward", this, &ASnakeBody::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASnakeBody::MoveRight);
}

void ASnakeBody::MoveForward(float axisvalue)
{
    // implementa qui il movimento in avanti del serpente usando l'input axisvalue
    // esempio: addmovementinput(getactorforwardvector(), axisvalue);
}

void ASnakeBody::MoveRight(float axisvalue)
{
    // implementa qui il movimento laterale del serpente usando l'input axisvalue
    // esempio: addmovementinput(getactorrightvector(), axisvalue);
}