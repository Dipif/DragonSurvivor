// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Attributes/DraHealthAttributeSet.h"
#include "GameplayEffectExtension.h"

UDraHealthAttributeSet::UDraHealthAttributeSet()
{
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
	InitDamage(0.0f);
	InitHealing(0.0f);
}
void UDraHealthAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	UE_LOG(LogTemp, Log, TEXT("UDraHealthAttributeSet::PostGameplayEffectExecute called for %s"), *GetNameSafe(this));
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Convert into -Health and then clamp
		const float DamageValue = GetDamage();
		const float OldHealthValue = GetHealth();
		const float MaxHealthValue = GetMaxHealth();
		const float NewHealthValue = FMath::Clamp(OldHealthValue - DamageValue, 0.0f, MaxHealthValue);
		UE_LOG(LogTemp, Log, TEXT("Damage applied: %f, Old Health: %f, New Health: %f"), DamageValue, OldHealthValue, NewHealthValue);

		if (OldHealthValue != NewHealthValue)
		{
			SetHealth(NewHealthValue);
		}
		SetDamage(0.0f);
	}
}