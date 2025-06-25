// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/BreathProjectileBase.h"
#include "NiagaraComponent.h"

ABreathProjectileBase::ABreathProjectileBase()
{
	BreathEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("BreathEffect"));
}
