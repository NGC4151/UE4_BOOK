// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingMesh.h"
#include "Particles/ParticleSystemComponent.h"
#include "ConstructorHelpers.h"
#include "Particles/ParticleSystem.h"
#include "SpawnCharactor.h"

// Sets default values
ABuildingMesh::ABuildingMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnInterval = 5.0;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;
	SpawnEffect = CreateDefaultSubobject<UParticleSystemComponent>("SpawnEffect");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object!=nullptr)
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	auto SpawnParticle = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (SpawnParticle.Object != nullptr)
	{
		SpawnEffect->SetTemplate(SpawnParticle.Object);
	}
	SpawnEffect->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	UnitToSpawn = ASpawnCharactor::StaticClass();
	
	}

// Called when the game starts or when spawned
void ABuildingMesh::BeginPlay()
{
	Super::BeginPlay();
	SpawnEffect->SetupAttachment(RootComponent);
	SpawnEffect->SetRelativeLocation(FVector(150,0,0));
	GetWorld()->GetTimerManager().SetTimer(SpawnTimeHandle, this, &ABuildingMesh::SpawnUnit, SpawnInterval, true);

	
}

// Called every frame
void ABuildingMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuildingMesh::SpawnUnit()
{
	
	FVector SpawnLocation = FVector(0, 0, 0);
	GetWorld()->SpawnActor(UnitToSpawn,&SpawnLocation);
	
}

void ABuildingMesh::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimeHandle);
}

