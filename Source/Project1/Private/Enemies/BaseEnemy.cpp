// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy.h"
#include "Components/CapsuleComponent.h"

ABaseEnemy::ABaseEnemy()
{
	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	RootComponent = CapsuleCollision;
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	TargetCharacter = Cast<ACharacterBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
