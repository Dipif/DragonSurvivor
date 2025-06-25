// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Blueprint/UserWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "DataAsset_InputConfig.h"
#include "Character/DragonPlayerController.h"
#include "Enemies/BaseEnemy.h"
#include "AnimInstances/DragonAnimInstance.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementSpeed = 10.f;
	RotationSpeed = 60.f;
	DestinationLocation = FVector::ZeroVector; // Initialize destination to zero vector
	InputConfigDataAsset = nullptr;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 1200.f;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	DestinationLocation = GetActorLocation(); // Initialize destination to current location

	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
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

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(InputConfigDataAsset->ClickMoveAction, ETriggerEvent::Triggered, this, &ACharacterBase::ClickMove);
	EnhancedInputComponent->BindAction(InputConfigDataAsset->ClickAttackAction, ETriggerEvent::Triggered, this, &ACharacterBase::ClickAttack);
}

void ACharacterBase::UpdateDestination(const FVector& NewDestination)
{
	DestinationLocation = NewDestination;
}

void ACharacterBase::ClickMove(const FInputActionValue& Value)
{
	FHitResult HitResult;
	ADragonPlayerController* PlayerController = Cast<ADragonPlayerController>(GetController());
	PlayerController->GetHitResultUnderCursor(ECC_Camera, false, HitResult);
	if (!HitResult.bBlockingHit)
		return;
	UpdateDestination(HitResult.ImpactPoint);
}

void ACharacterBase::ClickAttack(const FInputActionValue& Value)
{
}


void ACharacterBase::MoveTo(const FVector& Destination)
{
	if (GetController() && GetController()->GetPawn())
	{
		// Stop moving if close enough
		if (FVector::DistSquared(GetActorLocation(), Destination) < FMath::Square(50.f)) 
		{
			UpdateDestination(GetActorLocation());
			return;
		}

		FVector Direction = (DestinationLocation - GetActorLocation()).GetSafeNormal();
		Direction.Z = 0; // Ensure movement is horizontal
		SetActorRotation(Direction.Rotation()); // Rotate towards the direction of movement
		AddMovementInput(Direction, 1.0f);
	}
}
