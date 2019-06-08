// Fill out your copyright notice in the Description page of Project Settings.

#include "TestGameModeBase.h"
#include "UserProfile.h"
#include "Test.h"

void ATestGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//使用自己的日志标签输出消息
	UE_LOG(MyLog, Warning, TEXT("HI~"));

	int Value_int = 233;
	float Value_Float = 3.1415926;
	FString FStringVar = "Hello World";

	//使用日志输出多个不同类型的值
	UE_LOG(MyLog, Warning, TEXT("Text,%d,%f,%s"), Value_int, Value_Float, *FStringVar);

	//使用字符格式化参数来输出到Log
	FString name = "NGC4151";
	int32 Age = 22;
	TArray<FStringFormatArg>args;
	args.Add(FStringFormatArg(name));
	args.Add(FStringFormatArg(Age));
	FString string = FString::Format(TEXT("Name = {0} Age={1}"),args);
	UE_LOG(MyLog, Warning, TEXT("Your String: %s"), *string);

	ATestGameModeBase* gm = Cast<ATestGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gm)
	{
		UUserProfile* MyUserProfile = NewObject<UUserProfile>((UObject*)GetTransientPackage(), UUserProfile::StaticClass());

		if (MyUserProfile)
		{
			MyUserProfile->ConditionalBeginDestroy();
			MyUserProfile = nullptr;
		}
	}

	

}
