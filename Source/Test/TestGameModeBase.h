// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "TestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API ATestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void BeginPlay();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNmaes)
		TSubclassOf<UUserProfile>UPBlueprintClassName;
};
