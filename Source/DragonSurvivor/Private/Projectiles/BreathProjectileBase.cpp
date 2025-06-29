// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/BreathProjectileBase.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"
#include "Enemies/BaseEnemy.h"
#include "Engine/DamageEvents.h"
#include "NiagaraFunctionLibrary.h"
#include "AbilitySystemComponent.h"

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
	if (ABaseEnemy* BaseEnemy = Cast<ABaseEnemy>(Other))
	{
		if (UAbilitySystemComponent* ASC = BaseEnemy->GetAbilitySystemComponent())
		{
			FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
			EffectContext.AddSourceObject(this);

			FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(BaseEnemy->GE_Damage, 1.0f, EffectContext);
			if (SpecHandle.IsValid())
			{
				UE_LOG(LogTemp, Warning, TEXT("Applying damage to %s"), *BaseEnemy->GetName());
				ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
			}
		}
		ShowHitEffect(Hit);
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