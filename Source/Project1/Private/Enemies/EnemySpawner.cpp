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

	SpawnInterval = 1.0f; // Default spawn interval
	SpawnArea = FBox(FVector(-1000, -1000, 0), FVector(1000, 1000, 0)); // Default spawn area

	EnemyClass = nullptr; // Default enemy class is null
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnInterval, true);
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
	ABaseEnemy* SpawnedEnemy = GetWorld()->SpawnActor<ABaseEnemy>(EnemyClass, SpawnLocation, FRotator::ZeroRotator);
	float SpawnHeight = SpawnedEnemy->GetCapsuleCollision()->GetScaledCapsuleHalfHeight();
	SpawnedEnemy->SetActorLocation(FVector(SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z + SpawnHeight));
	SpawnedEnemies.Add(SpawnedEnemy);

	if (SpawnedEnemy)
	{
		AAIController* AIController = Cast<AAIController>(SpawnedEnemy->GetController());
		if (!AIController)
		{
			AIController = GetWorld()->SpawnActor<AAIController>(AAIController::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			AIController->Possess(SpawnedEnemy);
		}
	}
}