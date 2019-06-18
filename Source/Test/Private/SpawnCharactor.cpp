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
	auto MeshAsset= ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
if (MeshAsset.Object!=nullptr)
{
	MeshComp->SetStaticMesh(MeshAsset.Object);
}
MeshComp->SetupAttachment(RootComponent);
SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

}

// Called when the game starts or when spawned
void ASpawnCharactor::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0,0,FMath::RandRange(0,90)));
	RandomDirection = FVector(FMath::RandRange(0, 90), FMath::RandRange(0, 90), 0);
	SetLifeSpan(10.0f);
	

}

// Called every frame
void ASpawnCharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + RandomDirection);

}

// Called to bind functionality to input
void ASpawnCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

