// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ActorDied(AActor* DeadActor);

	bool IsGameActive() const { return bGameActive; }

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

protected:

	virtual void BeginPlay() override;

private:

	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;

	UPROPERTY(EditAnywhere)
	float StartDelay = 5.f;
	bool bGameActive;

	void HandleGameStart();
	void SetGameActive(bool bStarted) { bGameActive = bStarted;  }

	int32 TargetTowers = 0;
	int32 GetTargetTowerCount() const;
};
