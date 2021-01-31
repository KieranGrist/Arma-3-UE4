// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"

#include "MineralItem.generated.h"

class UVirtualItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UMineralItem : public UItemBase
{
	GENERATED_BODY()

public:
		FString ClassName();
		FString Amount();
		FString Zones();
		FString Item();
		FString Mined();
		FString ZoneSize();
		FString MakeString();

	//Name of the Mine
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ClassName;

		//Amount gathered
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Amount = 3;
		
		//Names of markers 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> _Zones;

		//Item required for gathering 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UVirtualItem* _Item;

	//Resource Mined in the zone 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UVirtualItem*> _ItemMined;

		//Size of the zone in meters
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ZoneSize = 30;	
		
	UFUNCTION(CallInEditor, Category = ItemBase)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = ItemBase)
		FString _ConfigText = "";

	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;
};
