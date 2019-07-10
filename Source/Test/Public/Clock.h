// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Clock.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class TEST_API AClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClock();

	UPROPERTY()
		USceneComponent* RootSceneComp;
	UPROPERTY(EditDefaultsOnly,Category="MeshComp")
		UStaticMeshComponent* ClockFace;
	UPROPERTY()
		USceneComponent* HourHandle;
	UPROPERTY(EditDefaultsOnly, Category = "MeshComp")
		UStaticMeshComponent* HourMesh;
	UPROPERTY()
		USceneComponent* MinuteHandle;
	UPROPERTY(EditDefaultsOnly, Category = "MeshComp")
		UStaticMeshComponent* MinuteMesh;
	UPROPERTY(EditDefaultsOnly, Category = "MeshComp")
		UStaticMeshComponent* SecondMesh;
	UPROPERTY()
		USceneComponent* SecondHandle;
	UFUNCTION()
		void TimeChanged(int32 hours, int32 Minutes,int32 Second);
	FDelegateHandle MyDelegateHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
