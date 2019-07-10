// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpSpawner.h"
#include "PickUpActor.h"

// Sets default values
APickUpSpawner::APickUpSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APickUpSpawner::PickUpCollected()
{
	GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &APickUpSpawner::SpawnPickUp, 10, false);
	CurrentPickUp->OnPickUp.Unbind();
	CurrentPickUp->Destroy();
}

void APickUpSpawner::SpawnPickUp()
{
	UWorld* MyWorld = GetWorld();
	if (MyWorld!=nullptr)
	{
		CurrentPickUp = MyWorld->SpawnActor<APickUpActor>(APickUpActor::StaticClass(), GetTransform());
		CurrentPickUp->OnPickUp.BindUObject(this, &APickUpSpawner::PickUpCollected);
	}
}

// Called when the game starts or when spawned
void APickUpSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnPickUp();
	
}

// Called every frame
void APickUpSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

