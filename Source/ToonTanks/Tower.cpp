// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanksGameMode.h"
#include "TimerManager.h"


// Called when the game starts or when spawned
void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    GetWorldTimerManager().SetTimer(
        FireRateTimerHandle,
        this,
        &ATower::CheckFireCondition,
        FireRate,
        true);
    ToonTanksGameMode = Cast<AToonTanksGameMode>(UGameplayStatics::GetGameMode(this));

}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (IsTankInFireRange())
    {
        RotateTurret(Tank->GetActorLocation());
    }

}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}


void ATower::CheckFireCondition()
{
    if (IsTankInFireRange())
    {
        Fire();
    }
}

bool ATower::IsTankInFireRange()
{
    if (Tank && ToonTanksGameMode && ToonTanksGameMode->IsGameActive())
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        return Distance <= FireRange;
    }
    return false;
}
