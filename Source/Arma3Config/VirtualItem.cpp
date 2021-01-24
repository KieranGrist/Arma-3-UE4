// Fill out your copyright notice in the Description page of Project Settings.
#include "VirtualItem.h"


FString UVirtualItem::MakeString()
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
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString UVirtualItem::ClassName()
{
	return ClassString(_VariableName.ToString(), _ClassTabs);
}

FString UVirtualItem::VariableName()
{
	return ClassMember("variable", _ClassMembersTabs, _VariableName.ToString());
}

FString UVirtualItem::DisplayName()
{
	return ClassMember("displayName", _ClassMembersTabs, _DisplayName.ToString());
}

FString UVirtualItem::ItemWeight()
{
	return ClassMember("weight", _ClassMembersTabs, _ItemWeight);
}

FString UVirtualItem::BuyPrice()
{
	return ClassMember("buyPrice", _ClassMembersTabs, _BuyPrice);
}

FString UVirtualItem::SellPrice()
{
	return ClassMember("sellPrice", _ClassMembersTabs, _SellPrice);
}

FString UVirtualItem::ItemIllegal()
{
	return ClassMember("illegal", _ClassMembersTabs, _ItemIllegal);
}

FString UVirtualItem::ItemEdible()
{
	return ClassMember("edible", _ClassMembersTabs, _ItemEdible);
}

FString UVirtualItem::ItemDrinkable()
{
	return ClassMember("drinkable", _ClassMembersTabs, _ItemDrinkable);
}

FString UVirtualItem::ItemIcon()
{
	return ClassMember("icon", _ClassMembersTabs, _ItemIcon);
}

FString UVirtualItem::ProcessedItem()
{
	return ClassMember("processedItem", _ClassMembersTabs, _ProcessedItem);
}

void UVirtualItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
