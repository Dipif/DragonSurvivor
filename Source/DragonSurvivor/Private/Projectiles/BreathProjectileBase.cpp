// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/BreathProjectileBase.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"
#include "Enemies/BaseEnemy.h"
#include "Engine/DamageEvents.h"
#include "NiagaraFunctionLibrary.h"

ABreathProjectileBase::ABreathProjectileBase()
{
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;

	BreathEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("BreathEffect"));
	BreathEffect->SetupAttachment(RootComponent);

	HitEffectClass = nullptr; // Initialize to nullptr
}

void ABreathProjectileBase::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (ABaseEnemy* baseEnemy = Cast<ABaseEnemy>(Other))
	{
		float Damage = 10.0f;
		baseEnemy->TakeDamage(Damage, FDamageEvent(), nullptr, this);
		ShowHitEffect(Hit);
		Destroy();
	}
	else if (Other && Other != this)
	{
		ShowHitEffect(Hit);
		Destroy();
	}
}

void ABreathProjectileBase::ShowHitEffect(const FHitResult& HitResult)
{
	if (HitEffectClass)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), HitEffectClass, HitResult.ImpactPoint);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit effect class is not set!"));
	}
}