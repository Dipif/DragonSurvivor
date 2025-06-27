// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Dragon.generated.h"

class ABreathProjectileBase;
/**
 * 
 */
UCLASS()
class PROJECT1_API ADragon : public ACharacterBase
{
	GENERATED_BODY()
public:
	ADragon();
	void Tick(float DeltaTime) override;
protected:
	virtual void ClickAttack(const FInputActionValue& Value) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* BreathSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
	TSubclassOf<ABreathProjectileBase> BreathProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
	float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
	float AttackDamage;

private:
	float TimeSinceLastAttack;

public:
	float GetAttackSpeed() const { return AttackSpeed; }
};
