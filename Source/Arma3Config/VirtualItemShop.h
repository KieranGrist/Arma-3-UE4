// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "VirtualItemShop.generated.h"

class UVehicleItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UVirtualItemShop : public UItemBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FName _ClassName;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FName _ShopName;
		
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSide _ShopSide = FSide::civ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FString _Conditions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UVirtualItem*> _Items;

	FString ClassName();
	FString ShopName();
	FString Conditions();
	FString Side();
	FString Items();
	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";


	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;

};
