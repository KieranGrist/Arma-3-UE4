// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "VirtualItem.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class ARMA3CONFIG_API UVirtualItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString MakeString();
	FString ClassName();
	FString VariableName();
	FString DisplayName();
	FString ItemWeight();
	FString BuyPrice();
	FString SellPrice();
	FString ItemIllegal();
	FString ItemEdible();
	FString ItemDrinkable();
	FString ItemIcon();
	FString ProcessedItem();

	//variable = Variable Name This is also the class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _VariableName;
	//displayName = Item Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _DisplayName;
	//weight = Item Weight
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ItemWeight = -1;
	//buyPrice = Item Buy Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _BuyPrice = -1;
	//sellPrice = Item Sell Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _SellPrice = -1;
	//illegal = Illegal Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _ItemIllegal = false;
	//edible = Item Edible(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ItemEdible = -1;
	//drinkable = Item Drinkable(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ItemDrinkable = -1;
	//icon = Item Icon
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ItemIcon;
	//Processed Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UVirtualItem* _ProcessedItem;


	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";


	int _ClassTabs = 2;
	int _ClassMembersTabs = 3;

};
