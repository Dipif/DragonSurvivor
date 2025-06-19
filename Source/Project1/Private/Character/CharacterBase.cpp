// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 1200.f;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	DestinationLocation = GetActorLocation(); // Initialize destination to current location
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo(DestinationLocation); // Move towards the destination location
}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::UpdateDestination(const FVector& NewDestination)
{
	DestinationLocation = NewDestination;
}


void ACharacterBase::MoveTo(const FVector& Destination)
{
	if (GetController() && GetController()->GetPawn())
	{
		FVector Direction = (DestinationLocation - GetActorLocation()).GetSafeNormal();
		Direction.Z = 0; // Ensure movement is horizontal
		SetActorRotation(Direction.Rotation()); // Rotate towards the direction of movement
		AddMovementInput(Direction, 1.0f);
	}
}

