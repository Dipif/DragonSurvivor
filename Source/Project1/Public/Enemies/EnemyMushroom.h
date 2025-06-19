// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "EnemyMushroom.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT1_API AEnemyMushroom : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AEnemyMushroom();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
protected:

	FVector DestinationLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MovementSpeed;

	UFUNCTION(BlueprintCallable)
	virtual void MoveTo(const FVector& Destination);

};
