// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMyGameState();

	UFUNCTION()
		void SetScore(int32 NewScore);
	UFUNCTION()
		int32 GetScore();

private:
	UPROPERTY()
		int32 CurrentScore;


	
};
