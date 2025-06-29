// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BaseAnimInstance.h"
#include "DragonAnimInstance.generated.h"

class ADragon;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class DRAGONSURVIVOR_API UDragonAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	void SetIsAttacking(bool IsAttacking);
	void SetAttackSpeed(float OtherAttackSpeed);

protected:
	UPROPERTY()
	ADragon* OwningDragonCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float CurrentSpeed = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bIsAttacking = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float AttackSpeed = 0.0f;
};
