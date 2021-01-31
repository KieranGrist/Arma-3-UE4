// Fill out your copyright notice in the Description page of Project Settings.
#include "CreateConfig.h"
#include "UObject/UObjectGlobals.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UCreateConfig::DataTableToUObjects()
{
	FString contextString = "UCreateConfig::DataTableToUObjects";
	TArray<FVItem*> vItems;
	_VirtualItems->GetAllRows<FVItem>(contextString, vItems);
	EObjectFlags flags = RF_Public | RF_Standalone;
	for (const auto vItem : vItems)
	{
		FString packageName = _Path + vItem->_VariableName.ToString();
		UPackage* package = CreatePackage(this, *packageName);


		UVirtualItem* newAsset = NewObject<UVirtualItem>(package, vItem->_VariableName, flags);

		if (newAsset != NULL)
		{
			newAsset->_VItem = *vItem;
		}

		FAssetRegistryModule::AssetCreated(newAsset);
		newAsset->MarkPackageDirty();
	}
}

void UCreateConfig::CrateOrUpdateTableRows()
{
	// Note to self, you can find rows by the row name update the row instead of creating it if found.
	FVItem* virtualItem;
	for (const auto itemPrefix : _ItemPrefixes)
	{
		virtualItem = _VirtualItems->FindRow<FVItem>(FName(itemPrefix.Key), "UCreateConfig::CrateOrUpdateTableRows()", false);
		if (!virtualItem)
		{
			virtualItem = new FVItem();
			virtualItem->_VariableName = FName(itemPrefix.Key);
			virtualItem->_DisplayName = FName(itemPrefix.Key);
			_VirtualItems->AddRow(FName(itemPrefix.Key), *virtualItem);
		}

		virtualItem->_BuyPrice = itemPrefix.Value;
		virtualItem->_ItemIllegal = false;
		virtualItem->_ProcessedItem = nullptr;
		for (const auto itemName : _ItemNames)
		{
			const FName itemCombinedName = FName(itemPrefix.Key + itemName.ToString());
			virtualItem = _VirtualItems->FindRow<FVItem>(itemCombinedName, "UCreateConfig::CrateOrUpdateTableRows()", false);
			if (!virtualItem)
			{
				virtualItem = new FVItem();
				virtualItem->_VariableName = FName(itemPrefix.Key);
				virtualItem->_DisplayName = FName(itemPrefix.Key);
				_VirtualItems->AddRow(FName(itemPrefix.Key), *virtualItem);
			}

			virtualItem->_ItemIllegal = true;
			virtualItem->_SellPrice = itemPrefix.Value * 2;
			virtualItem->_ProcessedItem = nullptr;
			_VirtualItems->AddRow(itemCombinedName, *virtualItem);
		}
	}

	for (const auto itemName : _ItemNames)
	{
		virtualItem = _VirtualItems->FindRow<FVItem>(itemName, "UCreateConfig::CrateOrUpdateTableRows()", false);
		if (!virtualItem)
		{
			virtualItem = new FVItem();
			virtualItem->_VariableName = itemName;
			virtualItem->_DisplayName = itemName;
			_VirtualItems->AddRow(FName(itemName), *virtualItem);
		}

		virtualItem->_ItemIllegal = true;
		virtualItem->_ProcessedItem = nullptr;
	}
}
