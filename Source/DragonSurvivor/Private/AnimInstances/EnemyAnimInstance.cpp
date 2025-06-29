// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/EnemyAnimInstance.h"
#include "Enemies/BaseEnemy.h"
#include "GameFramework/PawnMovementComponent.h"

void UEnemyAnimInstance::NativeInitializeAnimation()
{
	OwningEnemy = Cast<ABaseEnemy>(TryGetPawnOwner());
	if (OwningEnemy)
	{
		OwningMovementComponent = OwningEnemy->GetMovementComponent();
	}
}

void UEnemyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningEnemy)
	{
		return;
	}
	else if (!OwningMovementComponent)
	{
		OwningMovementComponent = OwningEnemy->GetMovementComponent();
		if (!OwningMovementComponent)
		{
			return;
		}
	}
	CurrentSpeed = OwningEnemy->GetVelocity().Size2D();
}
void UEnemyAnimInstance::SetIsAttacking(bool IsAttacking)
{
	this->bIsAttacking = IsAttacking;
}

void UEnemyAnimInstance::SetAttackSpeed(float OtherAttackSpeed)
{
	AttackSpeed = OtherAttackSpeed;
}