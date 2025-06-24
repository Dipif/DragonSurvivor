// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DragonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "DataAsset_InputConfig.h"
#include "Blueprint/UserWidget.h"

ADragonPlayerController::ADragonPlayerController(const FObjectInitializer& ObjectInitializer)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CurrentMouseCursor = EMouseCursor::Default;

}

void ADragonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);

	SetInputMode(InputMode);
}

void ADragonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	}


	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
	}
}