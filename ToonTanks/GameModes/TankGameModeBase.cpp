// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);// how many turret are there for the player to destroy 
    TargetTurrets = TurretActors.Num();

    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
    //Check what type of Actor died. If Turret, tally. If player -> go to lose condition 
    UE_LOG(LogTemp, Warning, TEXT("A Pawn Died"));
}

void ATankGameModeBase::HandleGameStart()
{
    // INitialise the start countdown, turret activation, pawn check etc
    // Call Blueprint version gameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call blueprint version GameOver(bool)
}