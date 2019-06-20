// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "MyActor.h"
#include "TestGameModeBase.generated.h"

//��׼�Ĵ���
DECLARE_DELEGATE(FStandarDelegateSignature)

//��һ�������Ĵ���
DECLARE_DELEGATE_OneParam(FParamDelegateSignature,FLinearColor)

UCLASS()
class TEST_API ATestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		ATestGameModeBase();

public:
    //�����ʵ��
	FStandarDelegateSignature MyStandarDelegate;
	FParamDelegateSignature MyParamDelegateSignature;

protected:

virtual	void BeginPlay()override;

UPROPERTY()
AMyActor* SpawningActor;

UFUNCTION()
void DestroyActorFunction();

FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNmaes)
		TSubclassOf<UUserProfile>UPBlueprintClassName;
};
