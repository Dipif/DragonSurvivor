// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectiles/Projectilebase.h"
#include "BreathProjectileBase.generated.h"

class UNiagaraComponent;
class USphereComponent;
class UNiagaraSystem;
/**
 * 
 */
UCLASS()
class DRAGONSURVIVOR_API ABreathProjectileBase : public AProjectilebase
{
	GENERATED_BODY()
public:
	ABreathProjectileBase();
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void ShowHitEffect(const FHitResult& HitResult) override;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraComponent* BreathEffect;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collision;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* HitEffectClass;
};
