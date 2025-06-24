// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DragonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "DataAsset_InputConfig.h"
#include "Blueprint/UserWidget.h"

void ADragonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	}


	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(InputConfigDataAsset->MouseMoveAction, ETriggerEvent::Triggered, this, &ADragonPlayerController::MouseMove);
	}
}

void ADragonPlayerController::MouseMove(const FInputActionValue& Value)
{
	// draw debug circle at the mouse position
	FVector2D MousePosition = Value.Get<FVector2D>();
	if (CursorWidget)
	{
		CursorWidget->SetPositionInViewport(MousePosition, false);
	}
}
