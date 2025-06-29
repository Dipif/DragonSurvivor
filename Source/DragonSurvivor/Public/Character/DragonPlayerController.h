// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/HighlightInterface.h"
#include "DragonPlayerController.generated.h"


class UDataAsset_InputConfig;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class DRAGONSURVIVOR_API ADragonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADragonPlayerController(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input Data", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	AActor* LastHitActor;
};
