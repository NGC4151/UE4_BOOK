// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpActor.generated.h"

class UStaticMeshComponent;
class URotatingMovementComponent;

DECLARE_DELEGATE(FPickUpedEventSignature)

UCLASS()
class TEST_API APickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActor();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;

	UPROPERTY(EditDefaultsOnly, Category = "Comp")
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditDefaultsOnly, Category = "Comp")
		URotatingMovementComponent* RotatingComp;

	FPickUpedEventSignature OnPickUp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
