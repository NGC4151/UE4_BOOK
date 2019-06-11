// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"
#include "UserProfile.generated.h"

/**
 * Blueprintable：这个修饰符使得C++类可以创建蓝图版本的类
 * BlueprintType：这个修饰符使得C++类可以将该类公开为可用于蓝图中的变量的类型。
 * NotBlueprintType：这个修饰符得防止将该类用于蓝图中的变量。
 */
UCLASS(Blueprintable, BlueprintType)
class TEST_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * UPROPERTY宏的修饰符：
	 * EditAnywhere: 被此修饰符修饰的值可以在蓝图类和每个实例中更改
	 * EditDefaultsOnly：被此修饰符修饰的值只能在蓝图类中修改
	 * EditInstanceOnly：被此修饰符修饰的值只能在蓝图类的实例中更改
	 * BlueprintReadWrite：被此修饰符修饰的值可以在蓝图图表中读写，该值必须是公有成员，否则将报错
	 * BlueprintReadOnly：被此修饰符修饰的值仅可在蓝图中读取，值必须在C++中设置，无法在蓝图中修改
	 * Category：此修饰符用于将变量分类
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Magic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
		TSubclassOf<UObject>UClassOfplayer;

	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
		FStringClassReference UClassGameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		FColoredTexture Texture;
};
