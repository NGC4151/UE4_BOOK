// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "MyActor.h"
#include "TestGameModeBase.generated.h"

//标准的代理
DECLARE_DELEGATE(FStandarDelegateSignature)

//带一个参数的代理
DECLARE_DELEGATE_OneParam(FParamDelegateSignature,FLinearColor)

UCLASS()
class TEST_API ATestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		ATestGameModeBase();

public:
    //代理的实例
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
