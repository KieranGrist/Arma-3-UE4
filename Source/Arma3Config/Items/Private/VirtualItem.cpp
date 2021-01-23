// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/VirtualItem.h"


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
	return ret;
}

FString UVirtualItem::ClassName()
{
	return Tab() + "class " + _VariableName.ToString() + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UVirtualItem::VariableName()
{
	return Tab() + "variable = " + Quote() + _VariableName.ToString() + Quote() + SemiColon(0) + NewLine();
}

FString UVirtualItem::DisplayName()
{
	return Tab() + "displayName = " + Quote() + _DisplayName.ToString() + Quote() + SemiColon(0) + NewLine();
}

FString UVirtualItem::ItemWeight()
{
	return "weight =" + FString::FromInt(_ItemWeight) + SemiColon(0) + NewLine();
}

FString UVirtualItem::BuyPrice()
{
	return "buyPrice =" + FString::FromInt(_BuyPrice) + SemiColon(0) + NewLine();
}

FString UVirtualItem::SellPrice()
{
	return "sellPrice =" + FString::FromInt(_SellPrice) + SemiColon(0) + NewLine();
}

FString UVirtualItem::ItemIllegal()
{
	return "illegal =" + _ItemIllegal + SemiColon(0) + NewLine();
}

FString UVirtualItem::ItemEdible()
{
	return "edible =" + FString::FromInt(_ItemEdible) + SemiColon(0) + NewLine();
}

FString UVirtualItem::ItemDrinkable()
{
	return "drinkable =" + FString::FromInt(_ItemDrinkable) + SemiColon(0) + NewLine();
}

FString UVirtualItem::ItemIcon()
{
	return "icon = " + Quote() + _ItemIcon + Quote() + SemiColon(0) + NewLine();
}

FString UVirtualItem::ProcessedItem()
{
	FString ret = "processedItem =";
	if (_ProcessedItem)
	{
		ret += Quote() + _ProcessedItem->_VariableName.ToString() + Quote();
	}
	return ret + NewLine() + ClosedBraketSemiColon(1);
}

void UVirtualItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
