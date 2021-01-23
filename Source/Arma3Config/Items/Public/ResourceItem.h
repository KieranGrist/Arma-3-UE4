// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "ResourceItem.generated.h"

class UVirtualItem;

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UResoruceItem : public UItemBase
{
	GENERATED_BODY()

public:
	FString ClassName();
	FString Amount();
	FString Zones();
	FString Item();
	FString ZoneSize();
	FString MakeString(bool isEndString);

	//Resource gathered in the zone 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UVirtualItem* _ItemGathered;

	//Amount gathered
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Amount = 3;

	//Names of markers 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> _Zones;

	//Item required for gathering 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UVirtualItem* _Item;

	//Size of the zone in meters
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ZoneSize = 30;

	UFUNCTION(CallInEditor, Category = ItemBase)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = ItemBase)
		FString _ConfigText = "";
};
