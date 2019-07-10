// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpSpawner.generated.h"

class APickUpActor;

UCLASS()
class TEST_API APickUpSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpSpawner();

	UPROPERTY()
		USceneComponent* SpawnLocation;
	UFUNCTION()
		void PickUpCollected();
	UFUNCTION()
		void SpawnPickUp();
	UPROPERTY()
		APickUpActor* CurrentPickUp;

	FTimerHandle MyTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
