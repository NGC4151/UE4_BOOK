// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTriggerBox.generated.h"

class UBoxComponent;

UCLASS()
class TEST_API AMyTriggerBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor)override;

	UPROPERTY()
	UBoxComponent* BoxComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
