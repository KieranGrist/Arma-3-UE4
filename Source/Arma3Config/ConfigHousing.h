// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ConfigHousing.generated.h"

class UHouseItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UConfigHousing : public UItemBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray <UHouseItem*> _HouseItems;

	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 0;
	int _ClassMembersTabs = 1;
};
