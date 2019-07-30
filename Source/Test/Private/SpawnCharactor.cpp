// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnCharactor.h"
#include "ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASpawnCharactor::ASpawnCharactor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("SpawnMesh");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}
	MeshComp->SetupAttachment(RootComponent);
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	VisualFX = CreateDefaultSubobject<UParticleSystemComponent>("VisualFX");

	auto SpawnParticle = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (SpawnParticle.Object != nullptr)
	{
		VisualFX->SetTemplate(SpawnParticle.Object);
	}
	VisualFX->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	VisualFX->bAutoDestroy = true;
	VisualFX->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void ASpawnCharactor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(10.0f);
}

// Called every frame
void ASpawnCharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() +FVector(10,0,0));

}

// Called to bind functionality to input
void ASpawnCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

