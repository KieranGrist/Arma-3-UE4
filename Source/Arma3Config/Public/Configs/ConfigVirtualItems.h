// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"

#include "ConfigVirtualItems.generated.h"

class UVirtualItemShop;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UConfigVirtualItems: public UItemBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray <UVirtualItemShop*> _Shops;

	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 0;
	int _ClassMembersTabs = 1;
};
