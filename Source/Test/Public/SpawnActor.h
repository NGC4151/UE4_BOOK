// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API USpawnActor : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnActor();

	UFUNCTION(BlueprintCallable, Category = Spawner)
		void Spawner();
	UPROPERTY(EditAnywhere, Category = Spawner)
		TSubclassOf<AActor>ActorToSpawn;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FTimerHandle SpawnHandle;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
