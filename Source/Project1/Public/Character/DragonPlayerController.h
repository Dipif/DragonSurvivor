// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DragonPlayerController.generated.h"


class UDataAsset_InputConfig;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class PROJECT1_API ADragonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> CursorWidgetClass;

	UUserWidget* CursorWidget;

	void MouseMove(const FInputActionValue& Value);
};
