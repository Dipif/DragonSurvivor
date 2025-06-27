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

	AttackSpeed = 1.0f;
	AttackDamage = 10.0f;
	TimeSinceLastAttack = 1000.0f;
}

void ADragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceLastAttack += DeltaTime;
}

void ADragon::ClickAttack(const FInputActionValue& Value)
{
	if (TimeSinceLastAttack * AttackSpeed < 1.0f)
		return;
	TimeSinceLastAttack = 0.0f;
	FHitResult HitResult;
	ADragonPlayerController* PlayerController = Cast<ADragonPlayerController>(GetController());
	PlayerController->GetHitResultUnderCursor(ECC_Camera, false, HitResult);
	if (!HitResult.bBlockingHit)
		return;

	;
	FVector TargetLocation;
	if (ABaseEnemy* TargetEnemy = Cast<ABaseEnemy>(HitResult.GetActor()))
	{
		TargetLocation = TargetEnemy->GetActorLocation();
		CurrentTargetEnemy = TargetEnemy;
	}
	else
	{
		TargetLocation = HitResult.ImpactPoint;
	}
	CurrentTargetLocation = TargetLocation;
	FVector Direction = (TargetLocation - GetActorLocation()).GetSafeNormal();
	Direction.Z = 0;

	// Rotate towards the target enemy and stop moving
	SetActorRotation(Direction.Rotation());
	UpdateDestination(GetActorLocation());

	UDragonAnimInstance* AnimInstance = Cast<UDragonAnimInstance>(GetMesh()->GetAnimInstance());
	AnimInstance->SetIsAttacking(true);

}

void ADragon::SpawnBreath()
{
	FVector SpawnLocation = BreathSpawnPoint->GetComponentLocation();
	FVector SpawnDirection = (CurrentTargetLocation - SpawnLocation).GetSafeNormal();
	ABreathProjectileBase* Breath = GetWorld()->SpawnActor<ABreathProjectileBase>(
		BreathProjectileClass, SpawnLocation, SpawnDirection.Rotation());
}
