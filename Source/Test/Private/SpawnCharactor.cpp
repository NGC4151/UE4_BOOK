// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnCharactor.h"
#include "ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASpawnCharactor::ASpawnCharactor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualRepresentation = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	auto ParticleSystem= ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
if (ParticleSystem.Object!=nullptr)
{
	VisualRepresentation->SetTemplate(ParticleSystem.Object);
}
VisualRepresentation->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

}

// Called when the game starts or when spawned
void ASpawnCharactor::BeginPlay()
{
	Super::BeginPlay();
	VisualRepresentation->SetupAttachment(RootComponent);
	
}

// Called every frame
void ASpawnCharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(10, 0, 0));

}

// Called to bind functionality to input
void ASpawnCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

