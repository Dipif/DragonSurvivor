// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AnimNotify_AttackEnded.h"
#include "Interfaces/Attackable.h"

void UAnimNotify_AttackEnded::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UE_LOG(LogTemp, Warning, TEXT("Attack ended notify triggered."));
	if (IAttackable* Attackable = Cast<IAttackable>(MeshComp->GetOwner()))
	{
		Attackable->AttackEnd();
	}
}
