// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Internationalization.h"
#include "Event_listenner.generated.h"

class AMyTriggerBox;
class UPointLightComponent;
class UStaticMeshComponent;
class UTextRenderComponent;

UCLASS()
class TEST_API AEvent_listenner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvent_listenner();

	UPROPERTY()
		UPointLightComponent* LightComp;
	UPROPERTY(EditAnywhere, Category = "Comp")
		AMyTriggerBox* TriggerBox;
	UPROPERTY(EditDefaultsOnly, Category = "Comp")
		UStaticMeshComponent* ViusalMesh;
	UPROPERTY(VisibleDefaultsOnly, Category = "Comp")
		UTextRenderComponent* TextShow;
	UFUNCTION()
		void OnTriggerEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//FText showText = LOCTEXT("mykey", "Declare_Event!");

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
