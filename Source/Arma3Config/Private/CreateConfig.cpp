// Fill out your copyright notice in the Description page of Project Settings.
#include "CreateConfig.h"
#include "UObject/UObjectGlobals.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UCreateConfig::DataTableToUObjects()
{
	FString contextString = "UCreateConfig::DataTableToUObjects";
	TArray<FVirtualItem*> vItems;
	_VirtualItems->GetAllRows<FVirtualItem>(contextString, vItems);
	EObjectFlags flags = RF_Public | RF_Standalone;
	for (auto vItem : vItems)
	{
		FString packageName = _Path + vItem->_VariableName.ToString();
		UPackage* package = CreatePackage(*packageName);


		UItemBase* newAsset = NewObject<UItemBase>(package, vItem->_VariableName, flags);

		if (newAsset != NULL)
		{
			newAsset->_Item = *vItem;
		}

		FAssetRegistryModule::AssetCreated(newAsset);
		newAsset->MarkPackageDirty();
	}
}

void UCreateConfig::CreateOrUpdateTableRows()
{
	switch (_ItemClass)
	{
	case EItemClass::VirtualItem:
		CreateVirtualItems();
		break;
	case EItemClass::ClothingItems:
		break;
	case EItemClass::GarageItems:
		break;
	case EItemClass::HouseItems:
		break;
	case EItemClass::LicenseItems:
		break;
	case EItemClass::MineralItems:
		break;
	case EItemClass::ProcessItems:
		break;
	case EItemClass::ResourceItems:
		break;
	case EItemClass::VehicleItems:
		break;
	case EItemClass::WeaponItems:
		break;
	case EItemClass::Containers:
		CreateContainerItems();
		break;
	default:
		break;
	}

}

void UCreateConfig::SetAllRowNames()
{
	for (auto rowName : _VirtualItems->GetRowNames())
	{
		_VirtualItems->FindRow<FVirtualItem>(rowName, "UCreateConfig::CrateOrUpdateTableRows()", false)->_RowName = rowName.ToString();
	}
}



FString ToString(FString prefix, float a)
{
	return " " + prefix + " " + FString::SanitizeFloat(a) + "\n";
}

FString ToString(FString prefix, int a)
{
	return " " + prefix + "= " + FString::FromInt(a) + "\n";
}

void UCreateConfig::GrabRows()
{
	TArray<FVirtualItem*> grabbedRows;
	_VirtualItems->GetAllRows<FVirtualItem>("UCreateConfig::GrabRows()", grabbedRows);
	_ExactItems.Empty();

	for (auto rowName : _GrabRowsContaining)
	{
		_ExactItems.Add(FindItem(grabbedRows, rowName));
	}
}

void UCreateConfig::RowsToDataTable()
{
	TArray<FContainerItem*> containers;
	_ContainerItems->GetAllRows<FContainerItem>("containers", containers);

	TArray<FVirtualItem*> grabbedRows;
	_VirtualItems->GetAllRows<FVirtualItem>("UCreateConfig::GrabRows()", grabbedRows);

	for (auto rowName : _GrabRowsContaining)
	{
		FVirtualItem exactItem = FindItem(_ExactItems, rowName);
		FContainerItem container = FindItem(containers, rowName);

		TArray<FVirtualItem> rowContainedItems = ListOfContainedItems(grabbedRows, rowName);

		for (auto containedItem : rowContainedItems)
		{
			FVirtualItem* virtualItem = _VirtualItems->FindRow<FVirtualItem>(FName(rowName), "UCreateConfig::RowsToDataTable");

			FString itemsStringDebug = UItemBase::NewLine() + "Items ";
			itemsStringDebug += "VirtualItem = " + virtualItem->_RowName + ", ";
			itemsStringDebug += "Exact item = " + exactItem._RowName + ", ";
			itemsStringDebug += "container = " + container._RowName + UItemBase::NewLine();
			itemsStringDebug += ToString("Container Buy Price", container._BuyPrice);
			itemsStringDebug += ToString("Container Weight", container._ItemWeight);


			int32 buyPrice = (exactItem._BuyPrice * container._ContainerSize) * container._Percentge;

			FString buyPriceStringDebug = ToString("Buy Price, Container", buyPrice);
			buyPriceStringDebug += ToString("Buy Price, No Container", exactItem._BuyPrice * container._ContainerSize);




			int32 sellPrice = (exactItem._SellPrice * container._ContainerSize) * container._Percentge;

			FString sellPriceStringDebug = ToString("Sell Price, Container", sellPrice);
			sellPriceStringDebug += ToString("Sell Price, No Container", exactItem._SellPrice * container._ContainerSize);



			int32 weight = (exactItem._ItemWeight * container._ContainerSize) + container._ItemWeight;

			FString weightStringDebug = ToString("Weight, Container", weight);
			sellPriceStringDebug += ToString("Weight, No Container", exactItem._ItemWeight * container._ContainerSize);

			virtualItem->_ItemIllegal = exactItem._ItemIllegal;
			virtualItem->_BuyPrice = FMath::Clamp(buyPrice, -1, buyPrice);
			virtualItem->_SellPrice = FMath::Clamp(sellPrice, -1, sellPrice);
			virtualItem->_ItemWeight = FMath::Clamp(weight, 1, weight);

			PresentNotification("RowsToDataTable" + itemsStringDebug + buyPriceStringDebug + sellPriceStringDebug + weightStringDebug);
		}
	}

	for (auto exactItem : _ExactItems)
	{
		FString rowName = exactItem._RowName;

		auto virtualItem = _VirtualItems->FindRow<FVirtualItem>(FName(rowName), "UCreateConfig::RowsToDataTable");

		virtualItem->_ItemIllegal = exactItem._ItemIllegal;

		virtualItem->_BuyPrice = FMath::Clamp(exactItem._BuyPrice, -1, exactItem._BuyPrice);

		virtualItem->_SellPrice = FMath::Clamp(exactItem._SellPrice, -1, exactItem._SellPrice);

		virtualItem->_ItemWeight = FMath::Clamp(exactItem._ItemWeight, 1, exactItem._ItemWeight);
	}
}

FString FClothingItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += DisplayName();
	ret += Price();
	ret += Conditions();
	ret += UItemBase::ClosedBrackets();

	ret += UItemBase::Comma(_IsEndString);
	return ret;
}

FString FClothingItem::ClassName()
{
	return UItemBase::LineClassName(_ClassName.ToString());
}

FString FClothingItem::DisplayName()
{
	return UItemBase::LineMember(_DisplayName, true);
}

FString FClothingItem::Conditions()
{
	return UItemBase::LineMember(_Conditions, false);
}

FString FClothingItem::Price()
{
	return UItemBase::LineMember(_Price, true);
}

FString FGarageItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += GarageSpawnPosition();
	ret += GarageSpawnDirection();
	ret += GarageBlacklist();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FGarageItem::ClassName()
{
	return UItemBase::ClassString(_ClassName.ToString(), _ClassTabs);
}

FString FGarageItem::Price()
{
	return UItemBase::ClassMember("price", _ClassMembersTabs, _Price);
}

FString FGarageItem::GarageSpawnPosition()
{
	return UItemBase::ClassMember("garageSpawnPos", _ClassMembersTabs, _GarageSpawnPosition);
}

FString FGarageItem::GarageSpawnDirection()
{
	return UItemBase::ClassMember("garageSpawnDir", _ClassMembersTabs, _GarageSpawnDirection);
}

FString FGarageItem::GarageBlacklist()
{
	return UItemBase::ClassMember("garageBlacklists", _ClassMembersTabs, _GarageBlacklist);
}

FString FHouseItem::MakeString()
{
	FString ret = ClassName();
	ret += Price();
	ret += NumberOfCrates();
	ret += RestrictedPositions();
	ret += CanGarage();
	ret += GarageSpawnPosition();
	ret += GarageSpawnDirection();
	ret += GarageBlacklist();
	ret += LightPosition();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FHouseItem::ClassName()
{
	return UItemBase::ClassString(_ClassName.ToString(), _ClassTabs);
}

FString FHouseItem::Price()
{
	return UItemBase::ClassMember("price", _ClassMembersTabs, _Price);
}

FString FHouseItem::NumberOfCrates()
{
	return UItemBase::ClassMember("numberCrates", _ClassMembersTabs, _NumberOfCrates);
}

FString FHouseItem::RestrictedPositions()
{
	return UItemBase::ClassMember("restrictedPos", _ClassMembersTabs, _RestrictedPositions);
}

FString FHouseItem::CanGarage()
{
	return UItemBase::ClassMember("canGarage", _ClassMembersTabs, _CanGarage);
}

FString FHouseItem::GarageSpawnPosition()
{
	return UItemBase::ClassMember("garageSpawnPos", _ClassMembersTabs, _GarageSpawnPosition);
}

FString FHouseItem::GarageSpawnDirection()
{
	return UItemBase::ClassMember("garageSpawnDir", _ClassMembersTabs, _GarageSpawnDirection);
}

FString FHouseItem::GarageBlacklist()
{
	return UItemBase::ClassMember("garageBlacklists", _ClassMembersTabs, _GarageBlacklist);
}

FString FHouseItem::LightPosition()
{
	return UItemBase::ClassMember("lightPos", _ClassMembersTabs, _LightPosition);
}

FString FLicenseItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += VariableName();
	ret += DisplayName();
	ret += Price();
	ret += LicenseIllegal();
	ret += LicenseSide();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FLicenseItem::ClassName()
{
	return UItemBase::ClassString(_VariableName.ToString(), _ClassTabs);
}

FString FLicenseItem::VariableName()
{
	return UItemBase::ClassMember("variable", _ClassMembersTabs, _VariableName.ToString());
}

FString FLicenseItem::DisplayName()
{
	return UItemBase::ClassMember("displayName", _ClassMembersTabs, _DisplayName.ToString());
}

FString FLicenseItem::Price()
{
	return UItemBase::ClassMember("price", _ClassMembersTabs, _Price);
}

FString FLicenseItem::LicenseIllegal()
{
	return UItemBase::ClassMember("illegal", _ClassMembersTabs, _LicenseIllegal);
}

FString FLicenseItem::LicenseSide()
{
	return UItemBase::ClassMember("side", _ClassMembersTabs, _LicenseSide);
}

FString FMineralItem::ClassName()
{
	return UItemBase::ClassString(_ClassName, _ClassTabs);
}

FString FMineralItem::Amount()
{
	return UItemBase::ClassMember("amount", _ClassMembersTabs, _Amount);
}

FString FMineralItem::Zones()
{
	return UItemBase::ClassMember("zones", _ClassMembersTabs, _Zones);
}

FString FMineralItem::Item()
{
	return UItemBase::ClassMember("item", _ClassMembersTabs, _Item);
}

FString FMineralItem::Mined()
{
	return UItemBase::ClassMember("mined", _ClassMembersTabs, _ItemMined);
}

FString FMineralItem::ZoneSize()
{
	return UItemBase::ClassMember("zoneSize", _ClassMembersTabs, _ZoneSize);
}

FString FMineralItem::MakeString()
{
	FString ret;
	if (!_ItemMined.Num() == 0)
	{
		return "No item has been set up, please fix";
	}
	ret += ClassName();
	ret += Amount();
	ret += Zones();
	ret += Item();
	ret += Mined();
	ret += ZoneSize();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FProcessItem::ClassName()
{
	return UItemBase::ClassString(_ClassName, _ClassTabs);
}

FString FProcessItem::MaterialsRequired()
{
	return VirtualMapToString("MaterialsReq", _ClassMembersTabs, _MaterialsRequired);;
}

FString FProcessItem::MaterialsGiven()
{
	TArray<FString> materialsGiven = { VirtualPairToString(_MaterialsGiven, false) };
	return UItemBase::ClassMember("MaterialsGive", _ClassMembersTabs, materialsGiven);
}

FString FProcessItem::ProgressBarText()
{
	return UItemBase::ClassMember("Text", _ClassMembersTabs, _ProgressBarText);
}

FString FProcessItem::NoLicenseCost()
{
	return UItemBase::ClassMember("NoLicenseCost", _ClassMembersTabs, _NoLicenseCost);
}

FString FProcessItem::MakeString()
{
	FString ret;
	if (!_MaterialsRequired.Num() == 0)
	{
		return "No item has been set up, please fix";
	}

	ret += ClassName();
	ret += MaterialsRequired();
	ret += MaterialsGiven();
	ret += ProgressBarText();
	ret += NoLicenseCost();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FProcessItem::VirtualPairToString(TPair<UItemBase*, int> pair, bool useComma)
{
	FString ret;

	ret += UItemBase::LineClassName(pair.Key->_Item._RowName);
	ret += UItemBase::LineMember(pair.Value, false);
	ret += UItemBase::ClosedBrackets() + UItemBase::Comma(useComma);
	return ret;
}

FString FProcessItem::VirtualMapToString(FString name, int classMemberTabs, TMap<UItemBase*, int> virtualItemMap)
{
	FString ret = UItemBase::Tab(classMemberTabs) + name + UItemBase::ContainerOpen();
	int i = 0;
	for (auto& Elem : virtualItemMap)
	{
		i++;
		ret += VirtualPairToString(Elem, i < virtualItemMap.Num());
	}
	ret += UItemBase::ClosedBracketSemiColon() + UItemBase::NewLine();
	return ret;
}

FString FResourceItem::ClassName()
{
	return UItemBase::ClassString(_ItemGathered->_Item._RowName, _ClassTabs);
}

FString FResourceItem::Amount()
{
	return UItemBase::ClassMember("amount", _ClassMembersTabs, _Amount);
}

FString FResourceItem::Zones()
{
	return UItemBase::ClassMember("zones", _ClassMembersTabs, _Zones);
}

FString FResourceItem::Item()
{
	return UItemBase::ClassMember("item", _ClassMembersTabs, _Item);
}

FString FResourceItem::ZoneSize()
{
	return UItemBase::ClassMember("zoneSize", _ClassMembersTabs, _ZoneSize);
}

FString FResourceItem::MakeString()
{
	FString ret;
	if (!_ItemGathered)
	{
		return "No item has been set up, please fix";
	}
	ret += ClassName();
	ret += Amount();
	ret += Zones();
	ret += Item();
	ret += ZoneSize();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FSpawnItem::ClassName()
{
	return UItemBase::ClassString(_ClassName, _ClassTabs);
}

FString FSpawnItem::DisplayName()
{
	return UItemBase::ClassMember("displayName", _ClassMembersTabs, _DisplayName);
}

FString FSpawnItem::SpawnMarker()
{
	return UItemBase::ClassMember("spawnMarker", _ClassMembersTabs, _SpawnMarker);
}

FString FSpawnItem::Icon()
{
	return UItemBase::ClassMember("icon", _ClassMembersTabs, _Icon);
}

FString FSpawnItem::Conditions()
{
	return UItemBase::ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString FSpawnItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += DisplayName();
	ret += SpawnMarker();
	ret += Icon();
	ret += Conditions();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FVehicleItem::ClassName()
{
	return UItemBase::ClassString(_ClassName.ToString(), _ClassTabs);
}

FString FVehicleItem::VirtualItemSpace()
{
	return UItemBase::ClassMember("vItemSpace", _ClassMembersTabs, _VirtualItemSpace);
}

FString FVehicleItem::Conditions()
{
	return UItemBase::ClassMember("conditions", _ClassMembersTabs, _Condition);
}

FString FVehicleItem::Price()
{
	return UItemBase::ClassMember("price", _ClassMembersTabs, _Price);
}

FString FVehicleItem::VehicleTextures()
{
	FString ret = UItemBase::Tab(_ClassMembersTabs) + "textures" + UItemBase::ContainerOpen();
	for (int i = 0; i < _VehicleTextures.Num(); i++)
	{
		ret += _VehicleTextures[i].MakeString();
		_VehicleTextures[i]._UseComma = i < _VehicleTextures.Num();
		_VehicleTextures[i]._ClassMemberTabs = _ClassMembersTabs + 1;
	}
	ret += UItemBase::ClosedBracketSemiColon() + UItemBase::NewLine();
	return ret;
}

FString FVehicleItem::MakeString()
{
	FString ret;
	ret += UItemBase::OpenBrackets();
	ret += ClassName();
	ret += VirtualItemSpace();
	ret += Conditions();
	ret += Price();
	ret += VehicleTextures();
	return ret;
}

FString FVehicleTexture::MakeString()
{
	FString ret = UItemBase::OpenBrackets(_ClassMemberTabs);
	ret += UItemBase::Quote();
	ret += _TextureName.ToString();
	ret += UItemBase::Comma(true);
	ret += UItemBase::Quote();
	ret += UItemBase::Side(_Side);
	ret += UItemBase::Quote();
	ret += UItemBase::Comma(true);
	ret += UItemBase::NewLine();
	ret += UItemBase::OpenBrackets(_ClassMemberTabs);
	for (int i = 0; i < _TexturePaths.Num(); i++)
	{
		ret += UItemBase::Tab(_ClassMemberTabs + 1);
		ret += UItemBase::Quote();
		ret += _TexturePaths[i];
		ret += UItemBase::Quote();
		ret += UItemBase::NewLine();
	}
	ret += UItemBase::ClosedBracketsComma(_ClassMemberTabs + 1);
	ret += UItemBase::Quote();
	ret += _Conditions;
	ret += UItemBase::Quote();
	ret += UItemBase::ClosedBrackets(0);
	ret += UItemBase::Comma(_UseComma);
	return ret;
}

FString FVirtualItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += VariableName();
	ret += DisplayName();
	ret += ItemWeight();
	ret += BuyPrice();
	ret += SellPrice();
	ret += ItemIllegal();
	ret += ItemEdible();
	ret += ItemDrinkable();
	ret += ItemIcon();
	ret += ProcessedItem();
	ret += UItemBase::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FVirtualItem::ClassName()
{
	return UItemBase::ClassString(_VariableName.ToString(), _ClassTabs);
}

FString FVirtualItem::VariableName()
{
	return UItemBase::ClassMember("variable", _ClassMembersTabs, _VariableName.ToString());
}

FString FVirtualItem::DisplayName()
{
	return UItemBase::ClassMember("displayName", _ClassMembersTabs, _DisplayName.ToString());
}

FString FVirtualItem::ItemWeight()
{
	return UItemBase::ClassMember("weight", _ClassMembersTabs, _ItemWeight);
}

FString FVirtualItem::BuyPrice()
{
	return UItemBase::ClassMember("buyPrice", _ClassMembersTabs, _BuyPrice);
}

FString FVirtualItem::SellPrice()
{
	return UItemBase::ClassMember("sellPrice", _ClassMembersTabs, _SellPrice);
}

FString FVirtualItem::ItemIllegal()
{
	return UItemBase::ClassMember("illegal", _ClassMembersTabs, _ItemIllegal);
}

FString FVirtualItem::ItemEdible()
{
	return UItemBase::ClassMember("edible", _ClassMembersTabs, _ItemEdible);
}

FString FVirtualItem::ItemDrinkable()
{
	return UItemBase::ClassMember("drinkable", _ClassMembersTabs, _ItemDrinkable);
}

FString FVirtualItem::ItemIcon()
{
	_ItemIcon = "icons\\Icon_" + _VariableName.ToString() + ".paa";
	return UItemBase::ClassMember("icon", _ClassMembersTabs, _ItemIcon);
}

FString FVirtualItem::ProcessedItem()
{
	if (!_ProcessedItem)
	{
		return FString();
	}
	return UItemBase::ClassMember("processedItem", _ClassMembersTabs, _ProcessedItem);
}

FString FWeaponItem::MakeString()
{
	FString ret;
	ret += UItemBase::OpenBrackets();
	ret += ClassName();
	ret += NickName();
	ret += BuyPrice();
	ret += SellPrice();
	ret += Conditions();
	ret += UItemBase::ClosedBrackets() + UItemBase::Comma(_IsEndString);
	return ret;
}

FString FWeaponItem::ClassName()
{
	return UItemBase::LineClassName(_ClassName.ToString());
}

FString FWeaponItem::NickName()
{
	return UItemBase::LineMember(_NickName, true);
}

FString FWeaponItem::BuyPrice()
{
	return UItemBase::LineMember(_BuyPrice, true);
}

FString FWeaponItem::SellPrice()
{
	return UItemBase::LineMember(_SellPrice, true);
}

FString FWeaponItem::Conditions()
{
	return UItemBase::LineMember(_Conditions, false);
}

FString UItemBase::MapName()
{
	return "Malden";
}

FString UItemBase::Quote()
{
	return "\"";
}

FString UItemBase::NewLine()
{
	return "\n";
}

FString UItemBase::Comma(bool useComma)
{
	if (!useComma)
	{
		return "";
	}
	return ", ";
}

FString UItemBase::Tab(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += "\t";
	}
	return tabs;
}

FString UItemBase::Side(ESide side)
{
	switch (side)
	{
	case  ESide::civ:
		return Quote() + "civ" + Quote();
		break;
	case ESide::cop:
		return Quote() + "cop" + Quote();
		break;
	case  ESide::med:
		return Quote() + "med" + Quote();
		break;
	}
	return "Error no side";
}

FString UItemBase::BoolToString(bool inBool)
{
	return inBool ? "true" : "false";
}

FString UItemBase::OpenBrackets(int tabCount)
{
	return Tab(tabCount) + "{ ";
}

FString UItemBase::ClosedBracketsComma(int tabCount)
{

	return Tab(tabCount) + "},";
}

FString UItemBase::ClosedBrackets(int tabCount)
{
	return Tab(tabCount) + "}";
}

FString UItemBase::ClosedBracketSemiColon(int tabCount)
{
	return Tab(tabCount) + "};";
}

FString UItemBase::SemiColon(int tabCount)
{
	return Tab(tabCount) + ";";
}

FString UItemBase::ContainerOpen()
{
	return "[] = " + OpenBrackets();
}

//LineStringCreators
FString UItemBase::LineClassName(FString className)
{
	return OpenBrackets(0) + LineMember(className, true);
}

FString UItemBase::LineMember(FString member, bool useComma)
{
	return Quote() + member + Quote() + Comma(useComma);
}

FString UItemBase::LineMember(int member, bool useComma)
{
	return FString::FromInt(member) + Comma(useComma);
}

FString UItemBase::LineMember(bool member, bool useComma)
{
	return BoolToString(member) + Comma(useComma);
}

FString UItemBase::LineSide(ESide member, bool useComma)
{
	return Side(member) + Comma(useComma);
}

//ClassStringCreators
FString UItemBase::ClassString(FString name, int classTabs)
{
	return Tab(classTabs) + "class " + name + NewLine() + OpenBrackets(classTabs) + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, int member)
{
	return Tab(classMemberTabs) + name + " = " + FString::FromInt(member) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, bool member)
{
	return Tab(classMemberTabs) + name + " = " + BoolToString(member) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, ESide member)
{
	return Tab(classMemberTabs) + name + " = " + Side(member) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, FString member)
{
	return Tab(classMemberTabs) + name + " = " + LineMember(member, false) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, FVector member)
{
	return Tab(classMemberTabs) + name + ContainerOpen() + member.ToString() + ClosedBrackets() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, UItemBase* member)
{
	return UItemBase::ClassMember("name", classMemberTabs, member->_Item._RowName);
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<FVector> vectors)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < vectors.Num(); i++)
	{
		ret += "{" + vectors[i].ToString() + ClosedBrackets() + Comma(i < vectors.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();;
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<int> intArray)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < intArray.Num(); i++)
	{
		ret += FString::FromInt(intArray[i]) + Comma(i < intArray.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<FString> stringArray)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < stringArray.Num(); i++)
	{
		ret += Quote() + stringArray[i] + Quote() + Comma(i < stringArray.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<UItemBase*> nameArray)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < nameArray.Num(); i++)
	{
		ret += Quote() + nameArray[i]->_Item._RowName + Quote() + Comma(i < nameArray.Num());;
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TMap<UItemBase*, FString>  nameMap)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	int i = 0;
	for (auto& Elem : nameMap)
	{
		i++;
		ret += LineClassName(Elem.Key->_Item._RowName);
		ret += LineMember(Elem.Value, false);
		ret += ClosedBrackets() + Comma(i < nameMap.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FContainerItem::FContainerItem(FString rowName)
{
	_RowName = rowName;
	_BuyPrice = 2350;
	_Percentge = 1.1f;
	if (rowName.Contains("Small"))
	{
		_ContainerSize = 10;
		_ItemWeight = 5;
	}

	if (rowName.Contains("Medium"))
	{
		_ContainerSize = 30;
		_ItemWeight = 10;
		_BuyPrice *= 2;
	}

	if (rowName.Contains("Large"))
	{
		_ContainerSize = 50;
		_ItemWeight = 15;
		_BuyPrice *= 2;
	}

	if (rowName.Contains("ExtraLarge"))
	{
		_ContainerSize = 70;
		_ItemWeight = 20;
		_BuyPrice *= 2;
	}

	if (rowName.Contains("Extreme"))
	{
		_ContainerSize = 100;
		_ItemWeight = 25;
		_BuyPrice *= 2;
	}

	if (rowName.Contains("Concealed"))
	{
		_Percentge = 1.3f;
		_BuyPrice *= 3;
	}

	if (rowName.Contains("Refrigerated"))
	{
		_BuyPrice *= 2;
		_Percentge = 1.5f;
	}

	_ContainerSize = FMath::Clamp(_ContainerSize, 1, _ContainerSize);
	_ItemWeight = FMath::Clamp(_ItemWeight, 1, _ItemWeight);
}