// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/DragonAnimInstance.h"
#include "Character/Dragon.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDragonAnimInstance::NativeInitializeAnimation()
{
	OwningDragonCharacter = Cast<ADragon>(TryGetPawnOwner());
	if (OwningDragonCharacter)
	{
		OwningMovementComponent = OwningDragonCharacter->GetCharacterMovement();
	}
}

void UDragonAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningDragonCharacter || !OwningMovementComponent)
	{
		return;
	}
	CurrentSpeed = OwningDragonCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().Size2D() > 0.0f;
}
