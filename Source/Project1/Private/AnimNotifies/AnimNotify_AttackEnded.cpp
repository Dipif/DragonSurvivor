// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AnimNotify_AttackEnded.h"
#include "Character/CharacterBase.h"
#include "AnimInstances/DragonAnimInstance.h"

void UAnimNotify_AttackEnded::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UE_LOG(LogTemp, Warning, TEXT("Attack ended notify triggered."));
	if (ACharacterBase* Character = Cast<ACharacterBase>(MeshComp->GetOwner()))
	{
		if (UDragonAnimInstance* AnimInstance = Cast<UDragonAnimInstance>(MeshComp->GetAnimInstance()))
		{
			AnimInstance->SetIsAttacking(false);  // 공격 끝났다고 알림
		}
	}
}
