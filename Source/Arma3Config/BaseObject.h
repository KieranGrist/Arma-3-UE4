// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Shops/ClothingShop.h"

#include "BaseObject.generated.h"

USTRUCT(BlueprintType)
struct FBaseStruct
{
	GENERATED_BODY()
public:

	FBaseStruct();
	virtual	 ~FBaseStruct();
	const FString Quote() const
	{
		return "\"";
	}
	const FString NewLine() const
	{
		return "\n";
	}
	const FString Comma() const
	{
		return ", ";
	}
	const FString Tab() const
	{
		return "	";
	}
	const FString OpenBrakets(const int tabCount) const;
	const FString ClosedBraketsComma(const int tabCount) const;
	const FString ClosedBrakets(const int tabCount) const;
	const FString ClosedBraketSemiColon(const int tabCount) const;
	const FString ContainerOpen(const int tabCount) const;
	virtual const FString MakeString(const bool isEndString) const;
	const FString ClassName() const;
	const FString VariableName() const;
	const FString DisplayName() const;
	const FString Conditions() const;

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
	virtual const FString MakeString(const bool isEndString) const override;
	const FString BuyPrice() const;
	const FString SellPrice() const;

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

	virtual const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FVirtualItem : public FBaseStruct
{
	GENERATED_BODY()
public:
	virtual const FString MakeString(const bool isEndString) const override;
	const FString Weight() const;

	const  FString Illegal() const;
	const  FString Edible() const;
	const FString Drinkable() const;
	const  FString Icon() const;

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
struct FContainer : public FBaseStruct
{
	GENERATED_BODY()
public:
	FContainer();
	FContainer(FName name);

	const FString MakeString(const bool isEndString) const override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FItemBase> _ContainerItems;

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UShopBase : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName _ShopName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FContainer> _Containers;
};

UCLASS(BlueprintType)
class AShopRepresentation : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ShopName;
};

UCLASS(BlueprintType)
class AClothingShopNPC : public AShopRepresentation
{
	GENERATED_BODY()
public:
	AClothingShopNPC();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClothingShop* _ClothingShop;
};



USTRUCT(BlueprintType)
struct FConfigWeaponShops : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigVirtualItems : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigVehicles : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigSpawnPoints : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigProcess : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigLoadouts : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;;
};

USTRUCT(BlueprintType)
struct FConfigLicenses : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigHousing : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigGather : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigGarages : public FBaseStruct
{
	GENERATED_BODY()
public:
	const FString MakeString(const bool isEndString) const override;
};

USTRUCT(BlueprintType)
struct FConfigClothing : public FBaseStruct
{
	GENERATED_BODY()
public:
	FConfigClothing();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UClothingShop*> _ClothingShops;
	const FString MakeString(const bool isEndString) const override;

};

UCLASS()
class ARMA3CONFIG_API UBaseObject : public UDataAsset
{
	GENERATED_BODY()
public:
	UBaseObject();
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