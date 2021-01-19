// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemBase.generated.h"

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UItemBase : public UDataAsset
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UItemBase();
	static  FString Quote()
	{
		return "\"";
	}

	static FString NewLine()
	{
		return "\n";
	}

	static FString Comma()
	{
		return ", ";
	}

	static  FString Tab()
	{
		return "	";
	}

	static FString OpenBrakets(int tabCount);

	static FString ClosedBraketsComma(int tabCount);

	static FString ClosedBrakets(int tabCount);

	static FString ClosedBraketSemiColon(int tabCount);

	static FString ContainerOpen(int tabCount);

	FString ClassName();

	FString VariableName();

	FString DisplayName();

	FString Conditions();

	FString BuyPrice();

	FString SellPrice();


	virtual FString MakeString(bool isEndString);

	//Class Name only used if this object will be a class
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayClassName"), Category = ItemBase)
		FName _ClassName = "Item Class name";

	//Variable Name in the config 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayVariableName"), Category = ItemBase)
		FName _VariableName = "Name of the variable";

	//Name  that will display 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayDisplayName"), Category = ItemBase)
		FString _DisplayName = "Nickname that will appear purely in the shop dialog";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayBuyPrice"), Category = ItemBase)
		int _BuyPrice = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplaySellPrice"), Category = ItemBase)
		int _SellPrice = -1;

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayConditions"), Category = ItemBase)
		FString _Conditions = "";

	UFUNCTION(CallInEditor, Category = ItemBase)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = ItemBase)
		FString _ConfigText = "";
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayClassName = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayVariableName = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayDisplayName = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayConditions = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayBuyPrice = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplaySellPrice = false;
};
