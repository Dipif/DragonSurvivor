// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "EnemyMushroom.generated.h"

/**
 * 
 */
UCLASS()
class DRAGONSURVIVOR_API AEnemyMushroom : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AEnemyMushroom();

	virtual void BeginPlay() override;

	// IAttackable implementation
	virtual void Attack() override;
	// IAttackable implementation end
protected:

};
