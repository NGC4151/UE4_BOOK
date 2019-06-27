// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "MulticastDelegateListener.generated.h"

class UPointLightComponent;

UCLASS()
class TEST_API AMulticastDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMulticastDelegateListener();

public:
	UFUNCTION()
		void ToggleLight();
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;

	UPROPERTY()
		UPointLightComponent* PointLightComp;

	FDelegateHandle MyDelegateHandle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
