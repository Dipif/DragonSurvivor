// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectiles/Projectilebase.h"
#include "BreathProjectileBase.generated.h"

class UNiagaraComponent;
class USphereComponent;
/**
 * 
 */
UCLASS()
class PROJECT1_API ABreathProjectileBase : public AProjectilebase
{
	GENERATED_BODY()
public:
	ABreathProjectileBase();

	UPROPERTY(EditDefaultsOnly)
	UNiagaraComponent* BreathEffect;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collision;
};
