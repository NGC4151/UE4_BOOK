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
			 * ͨ��GameMode���������´����DelegateListener���Enable������
			    Ȼ����TriggerBox����ô���󶨵Ĵ�����
			 */
			MyGameMode->MyStandarDelegate.ExecuteIfBound();

			//�������Ĵ�����������ã����������ࡢ���������֮��Ļ������ã�������ϡ�
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

