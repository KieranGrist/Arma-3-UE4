// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"
#include "Engine/DataTable.h"

#include "VirtualItem.generated.h"

USTRUCT(BlueprintType)
struct FVItem : public FTableRowBase
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Min = -1))
		int _ItemWeight = -1;

	//buyPrice = Item Buy Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Min = -1))
		int _BuyPrice = -1;

	//sellPrice = Item Sell Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Min = -1))
		int _SellPrice = -1;

	//Percentage to use when increase/decreasing the sell/buy price
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Min = -1, Max = 100))
		int _Percentage = -1;

	//illegal = Illegal Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _ItemIllegal = false;

	//edible = Item Edible(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Min = -1, Max = 100))
		int _ItemEdible = -1;

	//drinkable = Item Drinkable(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Min = -1, Max = 100))
		int _ItemDrinkable = -1;

	//icon = Item Icon
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ItemIcon;

	//Processed Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UVirtualItem* _ProcessedItem;

	int _ClassTabs = 2;

	int _ClassMembersTabs = 3;
};

UCLASS(BlueprintType)
class ARMA3CONFIG_API UVirtualItem : public UItemBase
{
	GENERATED_BODY()
public:
	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UFUNCTION(CallInEditor)
		void ApplyPercentge();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVItem _VItem;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
