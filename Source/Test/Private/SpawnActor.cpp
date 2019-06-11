// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnActor.h"

// Sets default values for this component's properties
USpawnActor::USpawnActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}

void USpawnActor::Spawner()
{
	UWorld* ThisWorld = GetWorld();
	if (ThisWorld!=nullptr)
	{
		FTransform CompTransform(this->GetComponentTransform());
		ThisWorld->SpawnActor(ActorToSpawn, &CompTransform);
	}
}

// Called when the game starts
void USpawnActor::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void USpawnActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

