// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "BaseObject.generated.h"

class UClothingShop;

USTRUCT(BlueprintType)
struct FBaseStruct
{
	GENERATED_BODY()
public:

	FBaseStruct();
	virtual	 ~FBaseStruct();
	static  FString Quote()
	{
		return "\"";
	}
	static  FString NewLine()
	{
		return "\n";
	}
	static  FString Comma()
	{
		return ", ";
	}
	static  FString Tab()
	{
		return "	";
	}
	static  FString OpenBrakets(int tabCount);
	static  FString ClosedBraketsComma(int tabCount);
	static  FString ClosedBrakets(int tabCount);
	static 	 FString ClosedBraketSemiColon(int tabCount);
	static  FString ContainerOpen(int tabCount);
	virtual  FString MakeString(bool isEndString);
	static 	 FString ClassName();
	static  FString VariableName();
	static  FString DisplayName();
	static  FString Conditions();

	//Class Name only used if this object will be a class
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayClassName"))
		FName _ClassName = "Item Class name";

	//Variable Name in the config 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayVariableName"))
		FName _VariableName = "Name of the variable";

	//Name  that will display 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayDisplayName"))
		FName _DisplayName = "Nickname that will appear purely in the shop dialog";

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayConditions"))
		FString _Conditions = "";

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayClassName = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayVariableName = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayDisplayName = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayConditions = false;
};

USTRUCT(BlueprintType)
struct FItemBase : public FBaseStruct
{
	GENERATED_BODY()
public:
	virtual  FString MakeString(bool isEndString) override;
	static FString BuyPrice();
	static FString SellPrice();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayBuyPrice"))
		int _BuyPrice = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplaySellPrice"))
		int _SellPrice = -1;
protected:
	bool bDisplayBuyPrice = false;
	bool bDisplaySellPrice = false;
};

USTRUCT(BlueprintType)
struct FClothingItem : public FItemBase
{
	GENERATED_BODY()
public:
	FClothingItem();

	virtual  FString MakeString(bool isEndString) override;
};

USTRUCT(BlueprintType)
struct FVirtualItem : public FBaseStruct
{
	GENERATED_BODY()
public:
	virtual  FString MakeString(bool isEndString) override;

	static FString Weight();
	static FString Illegal();
	static FString Edible();
	static FString Drinkable();
	static FString Icon();

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

USTRUCT(BlueprintType)
struct FContainer
{
	GENERATED_BODY()
public:
	FContainer();
	FContainer(FName name);
	FName _ContainerName = "Name";
	FString MakeString(bool isEndString);
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FItemBase> _ContainerItems;
};

USTRUCT(BlueprintType)
struct FConfigBase
{
	GENERATED_BODY()
public:
	virtual	 ~FConfigBase();
	virtual FString MakeString();
};

USTRUCT(BlueprintType)
struct FConfigWeaponShops : public FConfigBase
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FConfigVirtualItems : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigVehicles : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigSpawnPoints : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigProcess : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigLoadouts : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigLicenses : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigHousing : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigGather : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FConfigGarages : public FConfigBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType) 
struct FConfigClothing : public FConfigBase
{
	GENERATED_BODY()
public:
	FConfigClothing();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UClothingShop*> _ClothingShops;
	FString MakeString() override;

};

UCLASS()
class ARMA3CONFIG_API UConfigMaker : public UDataAsset
{
	GENERATED_BODY()
public:
	UConfigMaker();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigWeaponShops _ConfigWeaponShop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigVirtualItems _ConfigVirtualItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigVehicles _ConfigVehicles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigSpawnPoints _ConfigSpawnPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigProcess _ConfigProcess;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigLoadouts _ConfigLoadouts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigLicenses _ConfigLicenses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigHousing _ConfigHousing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigGather _ConfigGather;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigGarages _ConfigGarages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FConfigClothing _ConfigClothing;
};