// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/EnemySpawner.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "AIController.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnInterval = 5.0f; // Default spawn interval
	SpawnArea = FBox(FVector(-1000, -1000, 0), FVector(1000, 1000, 0)); // Default spawn area

	EnemyClass = nullptr; // Default enemy class is null
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnInterval, true, 0.0f);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpawner::SpawnEnemy()
{
	UE_LOG(LogTemp, Display, TEXT("Spawning enemy..."));
	FVector SpawnLocation = FMath::RandPointInBox(SpawnArea);
	SpawnLocation.Z = 1000.0f;
	ABaseEnemy* SpawnedEnemy = GetWorld()->SpawnActor<ABaseEnemy>(EnemyClass, SpawnLocation, FRotator::ZeroRotator);
	if (!SpawnedEnemy)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn enemy of class %s"), *EnemyClass->GetName());
		return;
	}
	float SpawnHeight = SpawnedEnemy->GetCapsuleCollision()->GetScaledCapsuleHalfHeight();
	SpawnedEnemy->SetActorLocation(FVector(SpawnLocation.X, SpawnLocation.Y, SpawnHeight));
	SpawnedEnemies.Add(SpawnedEnemy);

}