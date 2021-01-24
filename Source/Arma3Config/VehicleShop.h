// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "VehicleShop.generated.h"

class UVehicleItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UVehicleShop : public UItemBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FName _ShopName;
		
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSide _ShopSide = FSide::civ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FString _Conditions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<UVehicleItem*, FString> _Vehicles;

	FString ClassName();
	FString ShopName();
	FString Conditions();
	FString Side();
	FString Vehicles();
	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
