// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "ItemBase.generated.h"

UENUM(BlueprintType)
enum class FSide : uint8
{
	civ,
	cop,
	med
};

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

	static FString Comma(bool useComma)
	{
		if (!useComma)
		{
			return "";
	   }
		return ", ";
	}

	static  FString Tab()
	{
		return "	";
	}

	static FString Side(FSide side)
	{
		switch (side)
		{
		 case  FSide::civ:
		 return Quote() + "civ" + Quote();
		 break;
		 case FSide::cop:
			 return Quote() + "cop" + Quote();
			 break;
		 case  FSide::med:
			 return Quote() +  "med" + Quote();
			 break;
		}
		return "Error no side";
	}

	static FString BoolToString(bool inBool)
	{		
		return inBool ? "true" : "false";
	}


	static FString OpenBrakets(int tabCount);

	static FString ClosedBraketsComma(int tabCount);

	static FString ClosedBrakets(int tabCount);

	static FString ClosedBraketSemiColon(int tabCount);

	static FString SemiColon(int tabCount);

	static FString ContainerOpen(int tabCount);
};
