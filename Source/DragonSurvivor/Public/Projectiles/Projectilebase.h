// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectilebase.generated.h"

class UProjectileMovementComponent;
UCLASS()
class DRAGONSURVIVOR_API AProjectilebase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectilebase();
	virtual void ShowHitEffect(const FHitResult& HitResult);

protected:

public:	

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovement;
};
