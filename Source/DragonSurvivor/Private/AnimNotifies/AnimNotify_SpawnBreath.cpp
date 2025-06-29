// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AnimNotify_SpawnBreath.h"
#include "Character/Dragon.h"
#include "AnimInstances/DragonAnimInstance.h"

void UAnimNotify_SpawnBreath::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UE_LOG(LogTemp, Warning, TEXT("Spawn Breath notify triggered."));
	if (ADragon* Dragon = Cast<ADragon>(MeshComp->GetOwner()))
	{
		Dragon->SpawnBreath();
	}
}
