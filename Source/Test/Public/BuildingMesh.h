// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingMesh.generated.h"

class UParticleSystemComponent;

UCLASS()
class TEST_API ABuildingMesh : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildingMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Mesh��� */
	UPROPERTY()
		UStaticMeshComponent* MeshComp;
	/** Spawn������Ч�� */
	UPROPERTY()
		UParticleSystemComponent* SpawnEffect;
	/** ҪSpawn���� */
	UPROPERTY()
		UClass* UnitToSpawn;
	/** Spawn��ʱ���� */
	UPROPERTY()
		float SpawnInterval;
	/** Spawn������ִ�о����Spawn���� */
	UFUNCTION()
		void SpawnUnit();

	UFUNCTION()
		void EndPlay(const EEndPlayReason::Type EEndPlayReason)override;

	UPROPERTY()
		FTimerHandle SpawnTimerHandle;

};
