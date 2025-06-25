// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/Projectilebase.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectilebase::AProjectilebase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
}
