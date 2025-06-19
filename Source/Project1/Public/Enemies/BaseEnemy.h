// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Character/CharacterBase.h"
#include "BaseEnemy.generated.h"

class UCapsuleComponent;
/**
 * 
 */
UCLASS(Blueprintable)
class PROJECT1_API ABaseEnemy : public ABasePawn
{
	GENERATED_BODY()

public:
	ABaseEnemy();

	virtual void BeginPlay() override;

	UCapsuleComponent* GetCapsuleCollision() const { return CapsuleCollision; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACharacterBase* TargetCharacter;
};
