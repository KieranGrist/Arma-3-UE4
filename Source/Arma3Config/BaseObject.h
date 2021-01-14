// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "BaseObject.generated.h"

static const FString _Quote = "\"";
static const FString _NewLine = "\n";
static const FString _Comma = ", ";
static const FString _Tab = "	"
static const string OpenBrakets(const int tabCount);
static const string ClosedBraketsComma(const int tabCount);
static const string ClosedBrakets(const int tabCount);
static const string ClosedBraketSemiColon(const int tabCount);
static const string ContainerOpen(const int tabCount);

UCLASS(Blueprintable)
class ARMA3CONFIG_API UBaseObject : public UObject
{
	GENERATED_BODY()

	UBaseObject();
public:
	virtual const FString MakeString();
	const FString ClassName();
	const FString VariableName();
	const FString DisplayName();
	const FString Conditions();

	//Class Name only used if this object will be a class
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString _ClassName = "Item Classname";
	
	//Variable Name in the config 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName _VariableName = "Name of the variable";
	
	//Name  that will display 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName _DisplayName = "Nickname that will appear purely in the shop dialog";
	
	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString _Conditions = "";
};


class UItemBase : public UBaseObject
{
public:
	virtual const FString MakeString() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _BuyPrigce = -1;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _SellPrice = -1;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName _ItemName;
};

class UContainer
{
public:
	virtual const FString MakeString() override;

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
public:
	virtual const FString MakeString() override;
	FString Weight();
	FString Illegal();
	FString Edible();
	FString Drinkable();
	FString Icon();

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
	
};

class UConfigWeaponShops : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigVirtualItems : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigVehicles : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigSpawnPoints : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigProcess : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigLoadouts : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigLicenses : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigHousing : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigGather : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigGarages : public UBaseObject
{
	const FString MakeString() override;
};

class UConfigClothing : public UBaseObject
{
	const FString MakeString() override;
};