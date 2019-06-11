// Fill out your copyright notice in the Description page of Project Settings.

#include "TestGameModeBase.h"
#include "UserProfile.h"
#include "MyActor.h"
#include "Test.h"

void ATestGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//ʹ���Լ�����־��ǩ�����Ϣ
	UE_LOG(MyLog, Warning, TEXT("HI~"));

	int Value_int = 233;
	float Value_Float = 3.1415926;
	FString FStringVar = "Hello World";

	//ʹ����־��������ͬ���͵�ֵ
	UE_LOG(MyLog, Warning, TEXT("Text,%d,%f,%s"), Value_int, Value_Float, *FStringVar);

	//ʹ���ַ���ʽ�������������Log
	FString name = "NGC4151";
	int32 Age = 22;
	TArray<FStringFormatArg>args;
	args.Add(FStringFormatArg(name));
	args.Add(FStringFormatArg(Age));
	FString string = FString::Format(TEXT("Name = {0} Age={1}"), args);
	UE_LOG(MyLog, Warning, TEXT("Your String: %s"), *string);

	ATestGameModeBase* gm = Cast<ATestGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gm)
	{
		/**
		 * Here, UAction::StaticClass() gets you a base UClass * for the UAction object.
		   The first argument to NewObject< > is GetTransientPackage(), which simply
		   retrieves the transient package for the game. A package (UPackage) in UE4 is
		   just a data conglomerate. Here we use the Transient Package to store our
		   heap-allocated data. You could also use UPROPERTY() TSubclassOf<AActor> from
		   Blueprints to select a UClass instance.
		   The third argument (optional) is a combination of parameters that indicate
		   how UObject is treated by the memory management system.
		* ��̬����һ������
		 */

		UUserProfile* MyUserProfile = NewObject<UUserProfile>((UObject*)GetTransientPackage(), UUserProfile::StaticClass());

		if (MyUserProfile)
		{
			//���ٶ��󣬲���һ����ָ�븳ֵ��MyUserProfileָ�룻
			MyUserProfile->ConditionalBeginDestroy();
			MyUserProfile = nullptr;
		}

	}

	FTransform SpawnLocation;
	SpawningActor = GetWorld()->SpawnActor<AMyActor>(AMyActor::StaticClass(), SpawnLocation);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Actor had spawn!"));
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATestGameModeBase::DestroyActorFunction, 5);
}

void ATestGameModeBase::DestroyActorFunction()
{
	if (SpawningActor != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Actor had Destroyed!"));
		SpawningActor->Destroy();
	}
}
