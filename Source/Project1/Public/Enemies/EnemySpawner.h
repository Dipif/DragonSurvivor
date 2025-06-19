// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemies/BaseEnemy.h"
#include "EnemySpawner.generated.h"

UCLASS()
class PROJECT1_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawn Setting")
	float SpawnInterval;

	UPROPERTY(EditAnywhere, Category = "Spawn Setting")
	TSubclassOf<ABaseEnemy> EnemyClass;

	UPROPERTY(EditAnywhere, Category = "Spawn Setting")
	FBox SpawnArea;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void SpawnEnemy();
	FTimerHandle SpawnTimerHandle;
	TArray<AActor*> SpawnedEnemies;
};
