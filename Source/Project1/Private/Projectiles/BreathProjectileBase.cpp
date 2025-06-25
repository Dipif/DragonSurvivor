// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/BreathProjectileBase.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"

ABreathProjectileBase::ABreathProjectileBase()
{
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;

	BreathEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("BreathEffect"));
	BreathEffect->SetupAttachment(RootComponent);
}
