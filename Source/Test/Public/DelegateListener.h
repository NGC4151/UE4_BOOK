// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateListener.generated.h"

class UPointLightComponent;

UCLASS()
class TEST_API ADelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//EndPlay�ڱ�����ʱ���ã�Ӧ���������ƺ���
	virtual void EndPlay(const EEndPlayReason::Type EEndPlayReason)override;

	UPROPERTY()
	UPointLightComponent* PointLightComp;
	UFUNCTION()
		void EnableLight();
	UFUNCTION()
		void SetLightColor(FLinearColor LightColor,bool EnableLight);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
