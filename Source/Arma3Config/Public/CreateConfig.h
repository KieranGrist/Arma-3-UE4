// Fill out your copyright notice in the Description page of Project Settings.

#pragma 
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Containers/Map.h"

#include "CreateConfig.generated.h"

UENUM(BlueprintType)
enum class ESide : uint8
{
	civ,
	cop,
	med
};

USTRUCT(BlueprintType)
struct FItem : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere)
		FString  _RowName = "NoRowName";

	virtual FString MakeString() { return "Reached base item"; };
	virtual bool IsValid() const { return _RowName != "NoRowName"; }
};

USTRUCT(BlueprintType)
struct FVirtualItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString MakeString() override;

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

	bool IsValid() const override
	{
		return Super::IsValid() && _VariableName.IsValid() && _DisplayName.IsValid();
	}

	bool operator==(const FVirtualItem& a) const
	{
		return _VariableName == a._VariableName && _DisplayName == a._DisplayName && _RowName == a._RowName;
	}

	//variable = Variable Name This is also the class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _VariableName;

	//displayName = Item Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _DisplayName;

	//weight = Item Weight
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ClampMin = 1))
		int _ItemWeight = 1;

	//buyPrice = Item Buy Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ClampMin = -1))
		int _BuyPrice = -1;

	//sellPrice = Item Sell Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ClampMin = -1))
		int _SellPrice = -1;

	//Percentage to use when increase/decreasing the sell/buy price
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ClampMin = -1, ClampMax = 100))
		int _Percentage = -1;

	//illegal = Illegal Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _ItemIllegal = false;

	//edible = Item Edible(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ClampMin = -1, ClampMax = 100))
		int _ItemEdible = -1;

	//drinkable = Item Drinkable(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ClampMin = -1, ClampMax = 100))
		int _ItemDrinkable = -1;

	//icon = Item Icon
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ItemIcon;

	//Processed Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UItemBase* _ProcessedItem;

	int _ClassTabs = 2;

	int _ClassMembersTabs = 3;
};

FORCEINLINE uint32 GetTypeHash(FVirtualItem& b)
{
	return FCrc::MemCrc_DEPRECATED(&b, sizeof(FVirtualItem));
}

USTRUCT(BlueprintType)
struct FClothingItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString ClassName();

	FString DisplayName();

	FString Price();

	FString Conditions();

	FString MakeString() override;

	//Clothing item class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName = "NONE";

	//(Display Name, leave as blank for default) 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _DisplayName = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions = "";

	bool _IsEndString;
};

USTRUCT(BlueprintType)
struct FGarageItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString ClassName();

	FString Price();

	FString GarageSpawnPosition();

	FString GarageSpawnDirection();

	FString GarageBlacklist();

	FString MakeString() override;

	//Class name of the garage building
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName;

	//price - Cost of the garage
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	//worldToModel position to spawn vehicles
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector _GarageSpawnPosition;

	//garageSpawnDir - Offset to garage direction to spawn at(+-90 etc).It will be used in the manner : getDir _garage + spawnDir
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _GarageSpawnDirection;

	//garageBlacklists[] - List of blacklisted houses for buying garages
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector>_GarageBlacklist;

	int _ClassTabs = 2;

	int _ClassMembersTabs = 3;
};

USTRUCT(BlueprintType)
struct FHouseItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString ClassName();

	FString Price();

	FString NumberOfCrates();

	FString RestrictedPositions();

	FString CanGarage();

	FString GarageSpawnPosition();

	FString GarageSpawnDirection();

	FString GarageBlacklist();

	FString LightPosition();

	FString MakeString() override;

	//Class name of the garage building
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName;

	//price - Cost of the building
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		//numberCrates - Allowed number of crates
		int _NumberOfCrates;

	//restrictedPos[] - Same as the old fn_getBuildingPositions.A list of restricted building positions(i.e, to stop spawning outside, or by windows etc)	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int> _RestrictedPositions;

	//canGarage - True if the building can be used as a garage(need to buy ontop)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _CanGarage = false;

	//worldToModel position to spawn vehicles
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector _GarageSpawnPosition;

	//garageSpawnDir - Offset to garage direction to spawn at(+-90 etc).It will be used in the manner : getDir _garage + spawnDir
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _GarageSpawnDirection;

	//garageBlacklists[] - List of blacklisted houses for buying garages
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector>_GarageBlacklist;

	//WorldToModel position for the light
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector _LightPosition;;

	int _ClassTabs = 2;

	int _ClassMembersTabs = 3;
};

USTRUCT(BlueprintType)
struct FLicenseItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString MakeString()  override;

	FString ClassName();

	FString VariableName();

	FString DisplayName();

	FString Price();

	FString LicenseIllegal();

	FString LicenseSide();

	//variable = Variable Name This is also the class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _VariableName;

	//displayName = Item Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _DisplayName;

	//buyPrice = Item Buy Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	//illegal = Illegal Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _LicenseIllegal = false;

	//Side of the License
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ESide _LicenseSide = ESide::civ;

	int _ClassTabs = 1;

	int _ClassMembersTabs = 2;
};

USTRUCT(BlueprintType)
struct FMineralItem : public FItem
{
	GENERATED_USTRUCT_BODY()

public:
	FString ClassName();

	FString Amount();

	FString Zones();

	FString Item();

	FString Mined();

	FString ZoneSize();

	FString MakeString()  override;

	//Name of the ClampMine
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ClassName;

	//Amount gathered
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Amount = 3;

	//Names of markers 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> _Zones;

	//Item required for gathering 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UItemBase* _Item;

	//Resource ClampMined in the zone 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UItemBase*> _ItemMined;

	//Size of the zone in meters
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ZoneSize = 30;

	int _ClassTabs = 1;

	int _ClassMembersTabs = 2;
};

USTRUCT(BlueprintType)
struct FProcessItem : public FItem
{

	GENERATED_USTRUCT_BODY()

public:
	FString ClassName();

	FString MaterialsRequired();

	FString MaterialsGiven();

	FString ProgressBarText();

	FString NoLicenseCost();

	FString MakeString() override;

	static FString VirtualPairToString(TPair<UItemBase*, int> pair, bool useComma);

	static FString VirtualMapToString(FString name, int classMemberTabs, TMap<UItemBase*, int> virtualItemMap);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ClassName;

	//Resource gathered in the zone 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<UItemBase*, int> _MaterialsRequired;

	//MaterialsGive (Returned items) = Array - Format -> {{"ITEM CLASS",HOWMANY}}
	TPair<UItemBase*, int> _MaterialsGiven;


	//Text(Progress Bar Text)
	FString _ProgressBarText;

	// NoLicenseCost (Cost to process w/o license)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _NoLicenseCost = 30;

	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;
};

USTRUCT(BlueprintType)
struct FResourceItem : public FItem
{
	GENERATED_USTRUCT_BODY()

public:
	FString ClassName();

	FString Amount();

	FString Zones();

	FString Item();

	FString ZoneSize();

	FString MakeString() override;

	//Resource gathered in the zone 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UItemBase* _ItemGathered;

	//Amount gathered
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Amount = 3;

	//Names of markers 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> _Zones;

	//Item required for gathering 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UItemBase* _Item;

	//Size of the zone in meters
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _ZoneSize = 30;

	int _ClassTabs = 1;

	int _ClassMembersTabs = 2;
};

USTRUCT(BlueprintType)
struct FSpawnItem : public FItem
{
	GENERATED_USTRUCT_BODY()

public:
	FString ClassName();

	FString DisplayName();

	FString SpawnMarker();

	FString Icon();

	FString Conditions();

	FString MakeString() override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ClassName;

	//Whats displayed to the players
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _DisplayName;

	//Name Of Marker
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _SpawnMarker;

	//Icon Displayed
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Icon;

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions;

	int _ClassTabs = 2;

	int _ClassMembersTabs = 3;
};

USTRUCT(BlueprintType)
struct FVehicleTexture : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString MakeString() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _TextureName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ESide _Side;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> _TexturePaths;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions = "";

	int _ClassMemberTabs;

	bool _UseComma;
};

USTRUCT(BlueprintType)
struct FVehicleItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString ClassName();

	FString VirtualItemSpace();

	FString Conditions();

	FString Price();

	FString VehicleTextures();

	FString MakeString() override;

	//Clothing item class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName;

	//(Display Name, leave as blank for default) 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _VirtualItemSpace;

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Condition;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVehicleTexture> _VehicleTextures;

	int _ClassTabs = 1;

	int _ClassMembersTabs = 2;

	bool _IsEndString;
};

USTRUCT(BlueprintType)
struct FWeaponItem : public FItem
{
	GENERATED_USTRUCT_BODY()
public:
	FString ClassName();

	FString NickName();

	FString BuyPrice();

	FString SellPrice();

	FString Conditions();

	FString MakeString() override;

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

	//Must Return bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions = "";

	bool _IsEndString;
};

USTRUCT(BlueprintType)
struct FContainerItem : public FVirtualItem
{
	GENERATED_USTRUCT_BODY()
public:
	FContainerItem() {}
	// Percentage increase on sell price
	UPROPERTY(EditAnywhere)
		float _Percentge = 0;

	// How many items this container can fit
	UPROPERTY(EditAnywhere, Meta = (ClampMin = -1))
		int32 _ContainerSize = 0;
	const bool operator==(const FContainerItem& a) const
	{
		return _Percentge == a._Percentge && _ContainerSize == a._ContainerSize;
	}
	FContainerItem(FString rowName);
};

FORCEINLINE uint32 GetTypeHash(FContainerItem& b)
{
	return FCrc::MemCrc_DEPRECATED(&b, sizeof(FContainerItem));
}

UENUM(BlueprintType)
enum class EItemClass : uint8
{
	VirtualItem,
	ClothingItems,
	GarageItems,
	HouseItems,
	LicenseItems,
	MineralItems,
	ProcessItems,
	ResourceItems,
	VehicleItems,
	WeaponItems,
	Containers
};

UCLASS(Blueprintable, BlueprintType)
class ARMA3CONFIG_API UCreateConfig : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
		void PresentNotification(const FString& notificationToPrint);
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _VirtualItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _ClothingItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _GarageItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _HouseItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _LicenseItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _MineralItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _ProcessItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _ResourceItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _VehicleItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _WeaponItems;
	UPROPERTY(EditAnywhere, Category = "Configs")
		UDataTable* _ContainerItems;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		TArray<FString> _ItemPrefixes;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		bool _PrefixAfterName;
	// If true it will only combine the prefix and name and create one item for each instead of treating them as seperate items 
	UPROPERTY(EditAnywhere, Category = "Table Editor")
	bool _IsOnlyCombination;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		TArray<FName> _ItemNames;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		EItemClass _ItemClass;

	UFUNCTION(CallInEditor, Category = "Table Editor")
		void CreateOrUpdateTableRows();	

	UFUNCTION(CallInEditor, Category = "Table Editor")
		void SetAllRowNames();

	// VirtualItem
	UFUNCTION(CallInEditor, Category = "Object Editor")
		void DataTableToUObjects();

	UPROPERTY(EditAnywhere, Category = "Object Editor")
		FString _Path = "/Game/Arma3Config/Items/VirtualItems/";

	// Row Quick Editor
	UFUNCTION(CallInEditor, Category = "Row Quick Editor")
		void GrabRows();

	UFUNCTION(CallInEditor, Category = "Row Quick Editor")
		void RowsToDataTable();

	UPROPERTY(EditAnywhere, Category = "Row Quick Editor")
		TArray<FString> _GrabRowsContaining;

	TArray<FVirtualItem> _ExactItems;



private:
	void CreateVirtualItems()
	{
		FVirtualItem configItem;
		FName rowName;
		for (auto itemName : _ItemNames)
		{
			rowName = itemName;

			if (_VirtualItems->FindRow<FVirtualItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
			{
				_VirtualItems->RemoveRow(rowName);
			}

			configItem = FVirtualItem();
			configItem._RowName = rowName.ToString();
			configItem._VariableName = rowName;
			configItem._DisplayName = rowName;
			configItem._ProcessedItem = nullptr;

			_VirtualItems->AddRow(rowName, configItem);
		}

		for (auto itemPrefix : _ItemPrefixes)
		{
			rowName = FName(itemPrefix);

			if (_VirtualItems->FindRow<FVirtualItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
			{
				_VirtualItems->RemoveRow(rowName);
			}

			configItem = FVirtualItem();
			configItem._RowName = rowName.ToString();
			configItem._VariableName = rowName;
			configItem._DisplayName = rowName;
			configItem._ProcessedItem = nullptr;

			_VirtualItems->AddRow(rowName, configItem);

			for (auto itemName : _ItemNames)
			{
				rowName = _PrefixAfterName ? FName(itemName.ToString() + itemPrefix) : FName(itemPrefix + itemName.ToString());

				if (_VirtualItems->FindRow<FVirtualItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
				{
					_VirtualItems->RemoveRow(rowName);
				}

				configItem = FVirtualItem();
				configItem._RowName = rowName.ToString();
				configItem._VariableName = rowName;
				configItem._DisplayName = rowName;
				configItem._ProcessedItem = nullptr;

				_VirtualItems->AddRow(rowName, configItem);
			}
		}
	}



	void CreateContainerItems()
	{
		FContainerItem configItem;
		FName rowName;
		if (!_IsOnlyCombination)
		{
			for (auto itemName : _ItemNames)
			{
				rowName = itemName;

				if (_ContainerItems->FindRow<FContainerItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
				{
					_ContainerItems->RemoveRow(rowName);
				}

				configItem = FContainerItem(rowName.ToString());
				configItem._RowName = rowName.ToString();
				configItem._VariableName = rowName;
				configItem._DisplayName = rowName;
				configItem._ProcessedItem = nullptr;

				_ContainerItems->AddRow(rowName, configItem);
			}

			for (auto itemPrefix : _ItemPrefixes)
			{
				rowName = FName(itemPrefix);

				if (_ContainerItems->FindRow<FContainerItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
				{
					_ContainerItems->RemoveRow(rowName);
				}

				configItem = FContainerItem(rowName.ToString());
				configItem._RowName = rowName.ToString();
				configItem._VariableName = rowName;
				configItem._DisplayName = rowName;
				configItem._ProcessedItem = nullptr;

				_ContainerItems->AddRow(rowName, configItem);

				for (auto itemName : _ItemNames)
				{
					rowName = _PrefixAfterName ? FName(itemName.ToString() + itemPrefix) : FName(itemPrefix + itemName.ToString());

					if (_ContainerItems->FindRow<FContainerItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
					{
						_ContainerItems->RemoveRow(rowName);
					}

					configItem = FContainerItem(rowName.ToString());
					configItem._RowName = rowName.ToString();
					configItem._VariableName = rowName;
					configItem._DisplayName = rowName;
					configItem._ProcessedItem = nullptr;

					_ContainerItems->AddRow(rowName, configItem);
				}
			}
		}
		else
		{
			for (auto itemPrefix : _ItemPrefixes)
			{
				for (auto itemName : _ItemNames)
				{
					rowName = _PrefixAfterName ? FName(itemName.ToString() + itemPrefix) : FName(itemPrefix + itemName.ToString());

					if (_ContainerItems->FindRow<FContainerItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false))
					{
						_ContainerItems->RemoveRow(rowName);
					}

					configItem = FContainerItem(rowName.ToString());
					configItem._RowName = rowName.ToString();
			 		configItem._VariableName = rowName;
					configItem._DisplayName = rowName;
					configItem._ProcessedItem = nullptr;

					_ContainerItems->AddRow(rowName, configItem);
				}
			}

		}
	}

private:
	TArray<FVirtualItem> ListOfContainedItems(TArray<FVirtualItem*> virtualItems, FString rowName)
	{
		TArray<FVirtualItem> containedItem;
		for (FVirtualItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FVirtualItem> ListOfContainedItems(TArray<FVirtualItem> virtualItems, FString rowName)
	{
		TArray<FVirtualItem> containedItem;
		for (FVirtualItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FVirtualItem FindItem(TArray<FVirtualItem> virtualItems, FString rowName)
	{
		for (FVirtualItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FVirtualItem();
	}

	FVirtualItem FindItem(TArray<FVirtualItem*> virtualItems, FString rowName)
	{
		for (auto* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FVirtualItem();
	}

	TArray<FClothingItem> ListOfContainedItems(TArray<FClothingItem*> virtualItems, FString rowName)
	{
		TArray<FClothingItem> containedItem;
		for (FClothingItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FClothingItem> ListOfContainedItems(TArray<FClothingItem> virtualItems, FString rowName)
	{
		TArray<FClothingItem> containedItem;
		for (FClothingItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FClothingItem FindItem(TArray<FClothingItem> virtualItems, FString rowName)
	{
		for (FClothingItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FClothingItem();
	}

	FClothingItem FindItem(TArray<FClothingItem*> virtualItems, FString rowName)
	{
		for (FClothingItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FClothingItem();
	}

	TArray<FGarageItem> ListOfContainedItems(TArray<FGarageItem*> virtualItems, FString rowName)
	{
		TArray<FGarageItem> containedItem;
		for (FGarageItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FGarageItem> ListOfContainedItems(TArray<FGarageItem> virtualItems, FString rowName)
	{
		TArray<FGarageItem> containedItem;
		for (FGarageItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FGarageItem FindItem(TArray<FGarageItem> virtualItems, FString rowName)
	{
		for (FGarageItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FGarageItem();
	}

	FGarageItem FindItem(TArray<FGarageItem*> virtualItems, FString rowName)
	{
		for (FGarageItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FGarageItem();
	}

	TArray<FHouseItem> ListOfContainedItems(TArray<FHouseItem*> virtualItems, FString rowName)
	{
		TArray<FHouseItem> containedItem;
		for (FHouseItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FHouseItem> ListOfContainedItems(TArray<FHouseItem> virtualItems, FString rowName)
	{
		TArray<FHouseItem> containedItem;
		for (FHouseItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FHouseItem FindItem(TArray<FHouseItem> virtualItems, FString rowName)
	{
		for (FHouseItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FHouseItem();
	}

	FHouseItem FindItem(TArray<FHouseItem*> virtualItems, FString rowName)
	{
		for (FHouseItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FHouseItem();
	}

	TArray<FLicenseItem> ListOfContainedItems(TArray<FLicenseItem*> virtualItems, FString rowName)
	{
		TArray<FLicenseItem> containedItem;
		for (FLicenseItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FLicenseItem> ListOfContainedItems(TArray<FLicenseItem> virtualItems, FString rowName)
	{
		TArray<FLicenseItem> containedItem;
		for (FLicenseItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FLicenseItem FindItem(TArray<FLicenseItem> virtualItems, FString rowName)
	{
		for (FLicenseItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FLicenseItem();
	}

	FLicenseItem FindItem(TArray<FLicenseItem*> virtualItems, FString rowName)
	{
		for (FLicenseItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FLicenseItem();
	}

	TArray<FMineralItem> ListOfContainedItems(TArray<FMineralItem*> virtualItems, FString rowName)
	{
		TArray<FMineralItem> containedItem;
		for (FMineralItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FMineralItem> ListOfContainedItems(TArray<FMineralItem> virtualItems, FString rowName)
	{
		TArray<FMineralItem> containedItem;
		for (FMineralItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FMineralItem FindItem(TArray<FMineralItem> virtualItems, FString rowName)
	{
		for (FMineralItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FMineralItem();
	}

	FMineralItem FindItem(TArray<FMineralItem*> virtualItems, FString rowName)
	{
		for (FMineralItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FMineralItem();
	}

	TArray<FProcessItem> ListOfContainedItems(TArray<FProcessItem*> virtualItems, FString rowName)
	{
		TArray<FProcessItem> containedItem;
		for (FProcessItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FProcessItem> ListOfContainedItems(TArray<FProcessItem> virtualItems, FString rowName)
	{
		TArray<FProcessItem> containedItem;
		for (FProcessItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FProcessItem FindItem(TArray<FProcessItem> virtualItems, FString rowName)
	{
		for (FProcessItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FProcessItem();
	}

	FProcessItem FindItem(TArray<FProcessItem*> virtualItems, FString rowName)
	{
		for (FProcessItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FProcessItem();
	}

	TArray<FResourceItem> ListOfContainedItems(TArray<FResourceItem*> virtualItems, FString rowName)
	{
		TArray<FResourceItem> containedItem;
		for (FResourceItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FResourceItem> ListOfContainedItems(TArray<FResourceItem> virtualItems, FString rowName)
	{
		TArray<FResourceItem> containedItem;
		for (FResourceItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FResourceItem FindItem(TArray<FResourceItem> virtualItems, FString rowName)
	{
		for (FResourceItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FResourceItem();
	}

	FResourceItem FindItem(TArray<FResourceItem*> virtualItems, FString rowName)
	{
		for (FResourceItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FResourceItem();
	}

	TArray<FVehicleItem> ListOfContainedItems(TArray<FVehicleItem*> virtualItems, FString rowName)
	{
		TArray<FVehicleItem> containedItem;
		for (FVehicleItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FVehicleItem> ListOfContainedItems(TArray<FVehicleItem> virtualItems, FString rowName)
	{
		TArray<FVehicleItem> containedItem;
		for (FVehicleItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FVehicleItem FindItem(TArray<FVehicleItem> virtualItems, FString rowName)
	{
		for (FVehicleItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FVehicleItem();
	}

	FVehicleItem FindItem(TArray<FVehicleItem*> virtualItems, FString rowName)
	{
		for (FVehicleItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FVehicleItem();
	}

	TArray<FWeaponItem> ListOfContainedItems(TArray<FWeaponItem*> virtualItems, FString rowName)
	{
		TArray<FWeaponItem> containedItem;
		for (FWeaponItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FWeaponItem> ListOfContainedItems(TArray<FWeaponItem> virtualItems, FString rowName)
	{
		TArray<FWeaponItem> containedItem;
		for (FWeaponItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FWeaponItem FindItem(TArray<FWeaponItem> virtualItems, FString rowName)
	{
		for (FWeaponItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FWeaponItem();
	}

	FWeaponItem FindItem(TArray<FWeaponItem*> virtualItems, FString rowName)
	{
		for (FWeaponItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FWeaponItem();
	}

	TArray<FContainerItem> ListOfContainedItems(TArray<FContainerItem*> virtualItems, FString rowName)
	{
		TArray<FContainerItem> containedItem;
		for (FContainerItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Contains(rowName))
			{
				containedItem.Add(*virtualItem);
			}
		}
		return containedItem;
	}

	TArray<FContainerItem> ListOfContainedItems(TArray<FContainerItem> virtualItems, FString rowName)
	{
		TArray<FContainerItem> containedItem;
		for (FContainerItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Contains(rowName))
			{
				containedItem.Add(virtualItem);
			}
		}
		return containedItem;
	}

	FContainerItem FindItem(TArray<FContainerItem> virtualItems, FString rowName)
	{
		for (FContainerItem virtualItem : virtualItems)
		{
			if (virtualItem._RowName.Compare(rowName) == 0)
			{
				return virtualItem;
			}
		}
		return  FContainerItem();
	}

	FContainerItem FindItem(TArray<FContainerItem*> virtualItems, FString rowName)
	{
		for (FContainerItem* virtualItem : virtualItems)
		{
			if (virtualItem->_RowName.Compare(rowName) == 0)
			{
				return *virtualItem;
			}
		}
		return FContainerItem();
	}
};

UCLASS(BlueprintType)
class ARMA3CONFIG_API UItemBase : public UDataAsset
{
	GENERATED_BODY()

public:
	static FString MapName();

	static  FString Quote();
	static FString NewLine();
	static FString Comma(bool useComma);
	static  FString Tab(int tabCount);
	static FString Side(ESide side);
	static	FString BoolToString(bool inBool);
	static FString OpenBrackets(int tabCount = 0);
	static FString ClosedBracketsComma(int tabCount = 0);
	static FString ClosedBrackets(int tabCount = 0);
	static FString ClosedBracketSemiColon(int tabCount = 0);
	static FString SemiColon(int tabCount = 0);
	static FString ContainerOpen();

	//LineStringCreators
	static FString LineClassName(FString className);
	static FString LineMember(FString member, bool useComma);
	static FString LineMember(int member, bool useComma);
	static FString LineMember(bool member, bool useComma);
	static FString LineSide(ESide member, bool useComma);

	//ClassStringCreators
	static FString ClassString(FString name, int classTabs);
	static FString ClassMember(FString name, int classMemberTabs, int member);
	static FString ClassMember(FString name, int classMemberTabs, bool member);
	static FString ClassMember(FString name, int classMemberTabs, ESide member);
	static FString ClassMember(FString name, int classMemberTabs, FString member);
	static FString ClassMember(FString name, int classMemberTabs, FVector member);
	static FString ClassMember(FString name, int classMemberTabs, UItemBase* member);
	static FString ClassMember(FString name, int classMemberTabs, TArray<FVector> vectors);
	static FString ClassMember(FString name, int classMemberTabs, TArray<int> intArray);
	static FString ClassMember(FString name, int classMemberTabs, TArray<FString> stringArray);
	static FString ClassMember(FString name, int classMemberTabs, TArray<UItemBase*> virtualItem);
	static FString ClassMember(FString name, int classMemberTabs, TMap<UItemBase*, FString>  vehicleItems);

	FItem _Item;
};