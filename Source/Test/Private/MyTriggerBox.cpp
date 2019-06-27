// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerBox.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TestGameModeBase.h"

// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>("BoxComp");
	BoxComp->SetBoxExtent(FVector(200,200,100));

}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyTriggerBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Messge = FString::Printf(TEXT("%S Come in~"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, Messge);

	UWorld* TheWorld = GetWorld();
	if (TheWorld!=nullptr)
	{

		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		ATestGameModeBase* MyGameMode = Cast<ATestGameModeBase>(GameMode);
		if (MyGameMode!=nullptr)
		{
			/**
			 * 通过GameMode里声明的新代理绑定DelegateListener里的Enable函数，
			    然后在TriggerBox里调用代理绑定的代理函数
			 */
			MyGameMode->MyStandarDelegate.ExecuteIfBound();

			//带参数的代理，代理的作用：减少类与类、对象与对象之间的互相引用，减少耦合。
			auto color = FLinearColor(1, 0, 0, 1);
			MyGameMode->MyParamDelegateSignature.ExecuteIfBound(color);
		}
		
		MyGameMode->MyMulticastDelegate.Broadcast();

	}

}

void AMyTriggerBox::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Messge = FString::Printf(TEXT("%S Go Out~"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, Messge);
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

