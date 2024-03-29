// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeOfDayHandle.generated.h"

DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnTimeChangeSignature,int32,int32,int32)

UCLASS()
class TEST_API ATimeOfDayHandle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeOfDayHandle();

	FOnTimeChangeSignature OnTimeChanged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		int32 TimeScale;
	UPROPERTY()
		int32 Hours;
	UPROPERTY()
		int32 Minutes;
	UPROPERTY()
		float ElapsedSeconds;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
