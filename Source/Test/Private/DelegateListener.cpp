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
		}
	}

	
}

void ADelegateListener::EnableLight()
{
	PointLightComp->SetVisibility(true);
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

