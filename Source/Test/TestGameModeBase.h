// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "MyActor.h"
#include "TestGameModeBase.generated.h"

DECLARE_DELEGATE(FStandarDelegateSignature)
UCLASS()
class TEST_API ATestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		ATestGameModeBase();

public:
	FStandarDelegateSignature MyStandarDelegate;
	
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
