// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Dragon.h"

#include "Enemies/BaseEnemy.h"
#include "Character/DragonPlayerController.h"
#include "AnimInstances/DragonAnimInstance.h"
#include "Projectiles/FireBreathProjectile.h"
#include "GameFramework/CharacterMovementComponent.h"

ADragon::ADragon()
{
	BreathSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BreathSpawnPoint"));
	BreathSpawnPoint->SetupAttachment(RootComponent);
}

void ADragon::ClickAttack(const FInputActionValue& Value)
{
	FHitResult HitResult;
	ADragonPlayerController* PlayerController = Cast<ADragonPlayerController>(GetController());
	PlayerController->GetHitResultUnderCursor(ECC_Camera, false, HitResult);
	if (!HitResult.bBlockingHit)
		return;

	ABaseEnemy* TargetEnemy = Cast<ABaseEnemy>(HitResult.GetActor());
	if (TargetEnemy)
	{
		// Rotate towards the target enemy and stop moving
		FVector TargetLocation = TargetEnemy->GetActorLocation();
		FVector Direction = (TargetLocation - GetActorLocation()).GetSafeNormal();
		Direction.Z = 0;
		SetActorRotation(Direction.Rotation());
		UpdateDestination(GetActorLocation());

		UDragonAnimInstance* AnimInstance = Cast<UDragonAnimInstance>(GetMesh()->GetAnimInstance());
		AnimInstance->SetIsAttacking(true);

		FVector SpawnLocation = BreathSpawnPoint->GetComponentLocation();
		FVector SpawnDirection = (TargetLocation - SpawnLocation).GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *SpawnDirection.Rotation().ToString());
		ABreathProjectileBase* Breath = GetWorld()->SpawnActor<ABreathProjectileBase>(
			BreathProjectileClass, SpawnLocation, SpawnDirection.Rotation());
	}
}
