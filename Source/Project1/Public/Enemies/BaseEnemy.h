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
class PROJECT1_API ABaseEnemy : public ABasePawn, public IHighlightInterface, public IAttackable
{
	GENERATED_BODY()

public:
	ABaseEnemy();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// IAttackable implementation
	virtual void Attack() override;
	virtual void AttackEnd() override;
	// IAttackable implementation end

	UCapsuleComponent* GetCapsuleCollision() const { return CapsuleCollision; }
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
	float Health;
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
