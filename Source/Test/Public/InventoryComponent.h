// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AInventoryActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY()
		TArray<AInventoryActor*>CurrentInventory;
	UFUNCTION()
		int32 AddToInventory(AInventoryActor* ActorToAdd);
	UFUNCTION()
		void RemoveToInventory(AInventoryActor* ActorToRemove);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
