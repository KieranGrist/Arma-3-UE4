// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "BaseObject.generated.h"


UCLASS(Blueprintable)
class ARMA3CONFIG_API UBaseObject : public UObject
{
	GENERATED_BODY()
public:
	UBaseObject();

	FString _ClassName;
	FString _VariableName;
	FString _DisplayName;
	FString _Conditions;
	virtual const FString MakeString()
	{
		return "";
	};
};


class UItemBase : public UBaseObject
{
	FName _ItemName;
	int _BuyBrigce = -1;
	int _SellPrice = -1;

	virtual const FString MakeString() override
	{
		return "";
	};
	
};

class UContainer
{
	FName _ItemName;
	TArray<UItemBase> _ContainerItems;

};

class UPhysicalItem : public UBaseObject
{
	virtual const FString MakeString() override
	{
		return "";
	};
};

class UVirtualItem : public UBaseObject
{
		//Item Weight
		int _Weight = -1; 
		// illegal = Illegal Item
		bool _llegal = false;
		//Item Edible(-1 = Disabled, other values = added value)
		int _Edible = -1;	
		// Drinkable(-1 = Disabled, other values = added value)
		int _Drinkable = -1;
		//Icon Of the item
		FString _Icon = "Item Icon";

		virtual const FString MakeString() override
		{
			return "";
		};
};

class UConfigWeaponShops : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigVirtualItems : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigVehicles : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigSpawnPoints : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigProcess : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigLoadouts : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigLicenses : public UBaseObject
{
	const FString MakeString() override
	{
		return "";
	};
};

class UConfigHousing : public UBaseObject
{

	const FString MakeString() override
	{
		return "";
	};
};

class UConfigGather : public UBaseObject
{

	const FString MakeString() override
	{
		return "";
	};
};

class UConfigGarages : public UBaseObject
{

	const FString MakeString() override
	{
		return "";
	};
};

class UConfigClothing : public UBaseObject
{

	const FString MakeString() override
	{
		return "";
	};
};