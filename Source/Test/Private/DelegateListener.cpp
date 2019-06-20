// Fill out your copyright notice in the Description page of Project Settings.

#include "DelegateListener.h"
#include "Components/PointLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TestGameModeBase.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLightComp = CreateDefaultSubobject<UPointLightComponent>("PointLightComp");
	RootComponent = PointLightComp;

	PointLightComp->SetVisibility(false);
	PointLightComp->SetLightColor(FColor::Red);

}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UWorld* TheWorld = GetWorld();
	if (TheWorld!=nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		ATestGameModeBase* MyGameMode = Cast<ATestGameModeBase>(GameMode);

		if (MyGameMode!=nullptr)
		{
			MyGameMode->MyStandarDelegate.BindUObject(this, &ADelegateListener::EnableLight);
			MyGameMode->MyParamDelegateSignature.BindUObject(this, &ADelegateListener::SetLightColor,true);
		}
	}

	
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UWorld* TheWorld = GetWorld();
	if (TheWorld!=nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		ATestGameModeBase* MyGameMode = Cast<ATestGameModeBase>(GameMode);
		if (MyGameMode!=nullptr)
		{
			//解除代理绑定的函数
			MyGameMode->MyStandarDelegate.Unbind();
			MyGameMode->MyParamDelegateSignature.Unbind();
		}
	}
}

void ADelegateListener::EnableLight()
{
	PointLightComp->SetVisibility(true);
}

void ADelegateListener::SetLightColor(FLinearColor LightColor,bool EnableLight)
{
	PointLightComp->SetLightColor(LightColor);
	PointLightComp->SetVisibility(false);
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

