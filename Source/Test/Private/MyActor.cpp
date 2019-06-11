// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComp = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneComp;

	ChidSceneComp = CreateDefaultSubobject<USceneComponent>("ChidSceneComp");
	ChidSceneComp->SetupAttachment(SceneComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetupAttachment(SceneComp);

	MeshComp2 = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp2");
	MeshComp2->SetupAttachment(ChidSceneComp);

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object!=nullptr)
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
		MeshComp2->SetStaticMesh(MeshAsset.Object);
	}

	ChidSceneComp->SetRelativeTransform(
		FTransform(
			FRotator(0, 0, 0),
			FVector(250, 0, 0),
			FVector(0.1f)
		)
	);

}

FString AMyActor::tostring()
{
	return FString::Printf(TEXT("An instance of MyActor: %s"), *Name);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

