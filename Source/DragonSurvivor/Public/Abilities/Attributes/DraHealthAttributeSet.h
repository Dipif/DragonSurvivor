// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DraHealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class DRAGONSURVIVOR_API UDraHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UDraHealthAttributeSet();
	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;

	// Taken Damage
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Damage;

	// Taken Healing
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Healing;

	ATTRIBUTE_ACCESSORS_BASIC(UDraHealthAttributeSet, Health);
	ATTRIBUTE_ACCESSORS_BASIC(UDraHealthAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS_BASIC(UDraHealthAttributeSet, Damage);
	ATTRIBUTE_ACCESSORS_BASIC(UDraHealthAttributeSet, Healing);
};
