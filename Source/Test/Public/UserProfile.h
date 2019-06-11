// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"
#include "UserProfile.generated.h"

/**
 * Blueprintable��������η�ʹ��C++����Դ�����ͼ�汾����
 * BlueprintType��������η�ʹ��C++����Խ����๫��Ϊ��������ͼ�еı��������͡�
 * NotBlueprintType��������η��÷�ֹ������������ͼ�еı�����
 */
UCLASS(Blueprintable, BlueprintType)
class TEST_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * UPROPERTY������η���
	 * EditAnywhere: �������η����ε�ֵ��������ͼ���ÿ��ʵ���и���
	 * EditDefaultsOnly���������η����ε�ֵֻ������ͼ�����޸�
	 * EditInstanceOnly���������η����ε�ֵֻ������ͼ���ʵ���и���
	 * BlueprintReadWrite���������η����ε�ֵ��������ͼͼ���ж�д����ֵ�����ǹ��г�Ա�����򽫱���
	 * BlueprintReadOnly���������η����ε�ֵ��������ͼ�ж�ȡ��ֵ������C++�����ã��޷�����ͼ���޸�
	 * Category�������η����ڽ���������
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
