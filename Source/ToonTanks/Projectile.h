// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere, Category = "Combat")
	UParticleSystemComponent* SmokeTrailParticleSystemComponent;
	UPROPERTY(EditAnywhere, Category = "Combat")
	UParticleSystem* HitParticles;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float Damage = 50.f;
	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
    class UProjectileMovementComponent* MovementComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float InitialSpeed = 1300.f;

	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);

	FTimerHandle DestroyProjectileTimerHandle;
	float DestroyDelay = 3.f;
	void HandleDestruction();
	void DestroyDelegate() { Destroy(); }

};
