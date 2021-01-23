// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "ClothingItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ARMA3CONFIG_API UClothingItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString ClassName();

	FString DisplayName();

	FString Price();

	FString Conditions();

	FString MakeString(bool isEndString);

	//Clothing item class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName = "NONE";

	//(Display Name, leave as blank for default) 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _DisplayName = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions = "";

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
