// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"

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
		FName  _RowName;

	virtual FString MakeString() { return "Reached base item"; };

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

	bool operator==(const FVirtualItem& a) const
	{
		return _VariableName == a._VariableName && _DisplayName == a._DisplayName;
	}

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
		UItemBase* _ProcessedItem;

	int _ClassTabs = 2;

	int _ClassMembersTabs = 3;
};

FORCEINLINE uint32 GetTypeHash(const FVirtualItem& b)
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

	//Name of the Mine
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

	//Resource Mined in the zone 
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

UCLASS(Blueprintable, BlueprintType)
class ARMA3CONFIG_API UCreateConfig : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(CallInEditor, Category = "Object Editor")
		void DataTableToUObjects();

	UFUNCTION(CallInEditor, Category = "Table Editor")
		void DeleteRows();

	UFUNCTION(CallInEditor, Category = "Table Editor")
		void CreateOrUpdateTableRows();

	UFUNCTION(CallInEditor, Category = "Table Editor")
		void SetAllRowNames();

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		UDataTable* _VirtualItems;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		TArray<FString> _ItemPrefixes;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		bool _PrefixAfterName;

	UPROPERTY(EditAnywhere, Category = "Table Editor")
		TArray<FName> _ItemNames;

	UPROPERTY(EditAnywhere, Category = "Object Editor")
		FString _Path = "/Game/Arma3Config/Items/VirtualItems/";

	UPROPERTY(EditAnywhere, Category = "Row Quick Editor")
		FName _SearchForRowsContaining;
	
	// Array Element 1 = Price increase , 2 = weight
	UPROPERTY(EditAnywhere, Category = "Row Quick Editor")
		TMap<FName, TArray<int32>> _VirtualItemsQuickEditor;

	UPROPERTY(EditAnywhere, Category = "Row Quick Editor")
		FVirtualItem _ExactItem;

	UFUNCTION(CallInEditor, Category = "Row Quick Editor")
		void DataTableToQuickEditor();

	UFUNCTION(CallInEditor, Category = "Row Quick Editor")
		void QuickEditorToDataTable();
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