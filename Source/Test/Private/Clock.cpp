// Fill out your copyright notice in the Description page of Project Settings.

#include "Clock.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "TimeOfDayHandle.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComp = CreateDefaultSubobject<USceneComponent>("RootSceneComp");
	ClockFace = CreateDefaultSubobject<UStaticMeshComponent>("ClockFace");
	HourMesh = CreateDefaultSubobject<UStaticMeshComponent>("HourMesh");
	MinuteMesh = CreateDefaultSubobject<UStaticMeshComponent>("MinuteMesh");
	HourHandle = CreateDefaultSubobject<USceneComponent>("HourHandle");
	MinuteHandle = CreateDefaultSubobject<USceneComponent>("MinuteHandle");
	SecondHandle = CreateDefaultSubobject<USceneComponent>("SecondHandle");
	SecondMesh = CreateDefaultSubobject<UStaticMeshComponent>("SecondMesh");

	RootComponent = RootSceneComp;
	HourMesh->AttachToComponent(HourHandle,
		FAttachmentTransformRules::KeepRelativeTransform);
	MinuteMesh->AttachToComponent(MinuteHandle,
		FAttachmentTransformRules::KeepRelativeTransform);
	HourHandle->AttachToComponent(RootSceneComp,
		FAttachmentTransformRules::KeepRelativeTransform);
	MinuteHandle->AttachToComponent(RootSceneComp,
		FAttachmentTransformRules::KeepRelativeTransform);
	ClockFace->AttachToComponent(RootSceneComp,
		FAttachmentTransformRules::KeepRelativeTransform);
	SecondMesh->AttachToComponent(SecondHandle, FAttachmentTransformRules::KeepRelativeTransform);
	SecondHandle->AttachToComponent(RootSceneComp, FAttachmentTransformRules::KeepRelativeTransform);
	ClockFace->SetRelativeTransform(FTransform(FRotator(90, 0, 0),
		FVector(10, 0, 0),
		FVector(2, 2, 0.1)));
	HourMesh->SetRelativeTransform(FTransform(FRotator(0, 0, 0),
		FVector(0, 0, 25),
		FVector(0.1, 0.1, 0.5)));
	MinuteMesh->SetRelativeTransform(FTransform(FRotator(0, 0, 0),
		FVector(0, 0, 50),
		FVector(0.1, 0.1, 0.8)));
	SecondMesh->SetRelativeTransform(FTransform(FRotator(0, 0, 0),
		FVector(0, 0, 50),
		FVector(0.1, 0.1, 1)));
}

void AClock::TimeChanged(int32 hours, int32 Minutes,int32 Second)
{
	HourHandle->SetRelativeRotation(FRotator(0, 0, 30 * hours));
	MinuteHandle->SetRelativeRotation(FRotator(0, 0, 6 * Minutes));
	SecondHandle->SetRelativeRotation(FRotator(0, 0, 6 * Second));
}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*>TimeOfDayHandlers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandle::StaticClass(), TimeOfDayHandlers);

	if (TimeOfDayHandlers.Num()!=0)
	{
		auto TimeOfDayHandler = Cast<ATimeOfDayHandle>(TimeOfDayHandlers[0]);
		MyDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock::TimeChanged);
	}
	
}

// Called every frame
void AClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

