// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"

#include "WeaponItem.generated.h"

UCLASS(BlueprintType)
class ARMA3CONFIG_API UWeaponItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString ClassName();

	FString NickName();

	FString BuyPrice();

	FString SellPrice();

	FString Conditions();

	FString MakeString(bool isEndString);

	//Weapon Item Class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName = "NONE";
	//Nickname that will appear purely in the shop dialog
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _NickName = "";
	// Buy Price of the item, must always be more then sell price (Not affected by dynamic market)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _BuyPrice = -1;
	// Sell Price of the item, must always be less then the buy price (Not affected by dynamic market), To disable selling, this should be - 1
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _SellPrice = -1;
	//Must Return Bool 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions = "";

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
