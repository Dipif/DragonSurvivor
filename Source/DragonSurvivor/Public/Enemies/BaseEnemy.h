// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Character/CharacterBase.h"
#include "Interfaces/HighlightInterface.h"
#include "Interfaces/Attackable.h"
#include "BaseEnemy.generated.h"

class UCapsuleComponent;
/**
 * 
 */
UCLASS(Blueprintable)
class DRAGONSURVIVOR_API ABaseEnemy : public ABasePawn, public IHighlightInterface, public IAttackable, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseEnemy();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	// IAttackable implementation
	virtual void Attack() override;
	virtual void AttackEnd() override;
	// IAttackable implementation end

	UCapsuleComponent* GetCapsuleCollision() const { return CapsuleCollision; }



	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<UDraAbilitySystemComponent> AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<UDraHealthAttributeSet> HealthAttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TSubclassOf<UGameplayEffect> GE_Damage;

protected:
	virtual void MoveTo(const FVector& Destination, float DeltaTime);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACharacterBase* TargetCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMeshComp;

	FVector DestinationLocation;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float AttackSpeed;


	float TimeSinceLastAttack;

	bool bIsMovable;
};
