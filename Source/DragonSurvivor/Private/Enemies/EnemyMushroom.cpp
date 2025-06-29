// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/EnemyMushroom.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "AnimInstances/EnemyMushroomAnimInstance.h"
#include "AbilitySystemComponent.h"

AEnemyMushroom::AEnemyMushroom()
{
	PrimaryActorTick.bCanEverTick = true;
	DestinationLocation = FVector::ZeroVector;
	TimeSinceLastAttack = 1.0f;

}


void AEnemyMushroom::BeginPlay()
{
	Super::BeginPlay();
	DestinationLocation = GetActorLocation();

	if (UFloatingPawnMovement* MovementComponent = Cast<UFloatingPawnMovement>(GetMovementComponent()))
	{
		MovementComponent->MaxSpeed = MovementSpeed;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Movement component is not of type UFloatingPawnMovement in ABaseEnemy::BeginPlay"));
	}
}

void AEnemyMushroom::Attack()
{
	if (TimeSinceLastAttack * AttackSpeed < 1.0f)
		return;
	bIsMovable = false;
	TimeSinceLastAttack -= 1 / AttackSpeed;

	FVector TargetLocation = TargetCharacter->GetActorLocation();
	FVector Direction = (TargetLocation - GetActorLocation()).GetSafeNormal();
	Direction.Z = 0;
	SetActorRotation(Direction.Rotation());

	UEnemyAnimInstance* AnimInstance = Cast<UEnemyAnimInstance>(SkeletalMeshComp->GetAnimInstance());
	AnimInstance->SetIsAttacking(true);
	AnimInstance->SetAttackSpeed(AttackSpeed);


	if (UAbilitySystemComponent* ASC = TargetCharacter->GetAbilitySystemComponent())
	{
		FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(TargetCharacter->GE_Damage, 1.0f, EffectContext);
		if (SpecHandle.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Applying damage to target character in AEnemyMushroom::Attack"));
			ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}
