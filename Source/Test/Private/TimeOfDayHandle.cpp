// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeOfDayHandle.h"

// Sets default values
ATimeOfDayHandle::ATimeOfDayHandle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeOfDayHandle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeOfDayHandle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

