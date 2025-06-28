// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy.h"
#include "Components/CapsuleComponent.h"
#include "Engine/SkeletalMesh.h"


ABaseEnemy::ABaseEnemy()
{
	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	RootComponent = CapsuleCollision;
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComp->SetupAttachment(RootComponent);
	TargetCharacter = nullptr;

	Health = 20.0f;
	AttackDamage = 10.0f;
	AttackRange = 100.0f;
	AttackSpeed = 1.0f;
	MovementSpeed = 10.f;
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	TargetCharacter = Cast<ACharacterBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceLastAttack += DeltaTime;
	if (FVector::Dist2D(TargetCharacter->GetActorLocation(), GetActorLocation()) < AttackRange)
	{
		Attack(TargetCharacter);
		return;
	}
	MoveTo(TargetCharacter->GetActorLocation(), DeltaTime);
}

void ABaseEnemy::HighlightActor()
{
	if (SkeletalMeshComp && SkeletalMeshComp->GetSkeletalMeshAsset())
	{
		SkeletalMeshComp->SetRenderCustomDepth(true);
		SkeletalMeshComp->SetCustomDepthStencilValue(0);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SkeletalMeshComp or SkeletalMesh is null in ABaseEnemy::HighlightActor"));
	}
}

void ABaseEnemy::UnHighlightActor()
{
	if (SkeletalMeshComp && SkeletalMeshComp->GetSkeletalMeshAsset())
	{
		SkeletalMeshComp->SetRenderCustomDepth(false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SkeletalMeshComp or SkeletalMesh is null in ABaseEnemy::UnHighlightActor"));
	}
}

float ABaseEnemy::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	Health -= Damage; 
	if (Health <= 0.0f)
	{
		Destroy();
	}
	return Damage;
}

void ABaseEnemy::MoveTo(const FVector& Destination, float DeltaTime)
{
	DestinationLocation = Destination;
	if (GetController() && GetController()->GetPawn())
	{
		FVector Direction = (DestinationLocation - GetActorLocation()).GetSafeNormal();
		Direction.Z = 0; // Ensure movement is horizontal
		SetActorRotation(Direction.Rotation()); // Rotate towards the direction of movement
		AddMovementInput(Direction, 1.0f);
	}
}

void ABaseEnemy::Attack(ACharacterBase* CharacterBase)
{
	UE_LOG(LogTemp, Warning, TEXT("BaseEnemy Attack called"));
}
