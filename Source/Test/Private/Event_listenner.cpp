// Fill out your copyright notice in the Description page of Project Settings.

#include "Event_listenner.h"
#include "MyTriggerBox.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AEvent_listenner::AEvent_listenner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightComp = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = LightComp;

	ViusalMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	ViusalMesh->SetupAttachment(RootComponent);

	TextShow = CreateDefaultSubobject<UTextRenderComponent>("Text");
	TextShow->SetupAttachment(RootComponent);
	TextShow->SetText(TEXT("sadadlaskjdl"));
	TextShow->SetHorizontalAlignment(EHTA_Center);
	TextShow->SetTextRenderColor(FColor::Blue);
	TextShow->SetVisibility(false);

}

void AEvent_listenner::OnTriggerEvent()
{
	LightComp->SetLightColor(FLinearColor(0, 1, 0, 1));
	ViusalMesh->SetRelativeScale3D(FVector(1.5, 1.5, 1.5));
	TextShow->SetVisibility(true);
}

// Called when the game starts or when spawned
void AEvent_listenner::BeginPlay()
{
	Super::BeginPlay();

	if (TriggerBox!=nullptr)
	{
		TriggerBox->OnplayerEnter.AddUObject(this, &AEvent_listenner::OnTriggerEvent);
	}
	
}

// Called every frame
void AEvent_listenner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

