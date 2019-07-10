// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpActor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
APickUpActor::APickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	RotatingComp = CreateDefaultSubobject<URotatingMovementComponent>("RotatingComp");
	
	MeshComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RotatingComp->RotationRate = FRotator(10, 0, 10);
}

void APickUpActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OnPickUp.ExecuteIfBound();
}

// Called when the game starts or when spawned
void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

