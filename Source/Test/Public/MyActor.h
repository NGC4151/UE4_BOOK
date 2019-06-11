// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		FString Name;
	UFUNCTION(BlueprintCallable, Category = Properties)
		FString tostring();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category=Comp)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category = Comp)
		UStaticMeshComponent* MeshComp2;
	UPROPERTY(VisibleAnywhere, Category = Comp)
		USceneComponent* SceneComp;
	UPROPERTY(VisibleAnywhere, Category = Comp)
		USceneComponent* ChidSceneComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
