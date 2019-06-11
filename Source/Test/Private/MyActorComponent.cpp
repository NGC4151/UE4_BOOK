// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	MovementRadius = 5.0f;

}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* CompOwner = GetOwner();

	if (CompOwner)
	{
		auto NewPos = CompOwner->GetActorLocation() + FVector(
			FMath::FRandRange(-1, 1)*MovementRadius,
			FMath::FRandRange(-1, 1)*MovementRadius,
			FMath::FRandRange(-1, 1)*MovementRadius);

		CompOwner->SetActorLocation(NewPos);
	}


}

