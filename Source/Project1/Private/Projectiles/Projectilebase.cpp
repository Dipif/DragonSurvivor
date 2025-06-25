// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/Projectilebase.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectilebase::AProjectilebase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent")); 
	ProjectileMovement->InitialSpeed = 500.f;
	ProjectileMovement->MaxSpeed = 500.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
}
