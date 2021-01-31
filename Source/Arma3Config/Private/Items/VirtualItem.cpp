// Fill out your copyright notice in the Description page of Project Settings.
#include "Items/VirtualItem.h"


FString FVItem::MakeString()
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
	ret += UVirtualItem::ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString FVItem::ClassName()
{
	return UVirtualItem::ClassString(_VariableName.ToString(), _ClassTabs);
}

FString FVItem::VariableName()
{
	return UVirtualItem::ClassMember("variable", _ClassMembersTabs, _VariableName.ToString());
}

FString FVItem::DisplayName()
{
	return UVirtualItem::ClassMember("displayName", _ClassMembersTabs, _DisplayName.ToString());
}

FString FVItem::ItemWeight()
{
	return UVirtualItem::ClassMember("weight", _ClassMembersTabs, _ItemWeight);
}

FString FVItem::BuyPrice()
{
	return UVirtualItem::ClassMember("buyPrice", _ClassMembersTabs, _BuyPrice);
}

FString FVItem::SellPrice()
{
	return UVirtualItem::ClassMember("sellPrice", _ClassMembersTabs, _SellPrice);
}

FString FVItem::ItemIllegal()
{
	return UVirtualItem::ClassMember("illegal", _ClassMembersTabs, _ItemIllegal);
}

FString FVItem::ItemEdible()
{
	return UVirtualItem::ClassMember("edible", _ClassMembersTabs, _ItemEdible);
}

FString FVItem::ItemDrinkable()
{
	return UVirtualItem::ClassMember("drinkable", _ClassMembersTabs, _ItemDrinkable);
}

FString FVItem::ItemIcon()
{
	_ItemIcon = "icons\\Icon_" + _VariableName.ToString() + ".paa";
	return UVirtualItem::ClassMember("icon", _ClassMembersTabs, _ItemIcon);
}

FString FVItem::ProcessedItem()
{
	if (!_ProcessedItem)
	{
		return FString();
	}
	return UVirtualItem::ClassMember("processedItem", _ClassMembersTabs, _ProcessedItem);
}

void UVirtualItem::UpdateConfigText()
{
	_ConfigText = _VItem.MakeString();
}

void UVirtualItem::ApplyPercentge()
{

}
