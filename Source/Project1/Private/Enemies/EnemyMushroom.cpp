// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/EnemyMushroom.h"

AEnemyMushroom::AEnemyMushroom()
{
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 0.5f;
	DestinationLocation = FVector::ZeroVector;

}


void AEnemyMushroom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo(TargetCharacter->GetActorLocation());
}

void AEnemyMushroom::BeginPlay()
{
	Super::BeginPlay();
	DestinationLocation = GetActorLocation();
}

void AEnemyMushroom::MoveTo(const FVector& Destination)
{
	DestinationLocation = Destination;
	if (GetController() && GetController()->GetPawn())
	{
		FVector Direction = (DestinationLocation - GetActorLocation()).GetSafeNormal();
		Direction.Z = 0; // Ensure movement is horizontal
		SetActorRotation(Direction.Rotation()); // Rotate towards the direction of movement
		AddMovementInput(Direction, 0.5f);
	}
}