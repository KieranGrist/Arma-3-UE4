// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "ConfigGarages.generated.h"

class UGarageItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UConfigGarages : public UItemBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray <UGarageItem*> _GarageItems;

	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 0;
	int _ClassMembersTabs = 1;
};
