// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameState.h"

AMyGameState::AMyGameState()
{
	CurrentScore = 0;
}

void AMyGameState::SetScore(int32 NewScore)
{
	CurrentScore = NewScore;
}

int32 AMyGameState::GetScore()
{
	return CurrentScore;
}
