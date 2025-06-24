// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Cursor.h"

// Sets default values
ACursor::ACursor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACursor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACursor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

