// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseObject.h"

UConfigMaker::UConfigMaker()
{

}

FBaseStruct::FBaseStruct()
{

}

FString FBaseStruct::MakeString(bool isEndString)
{
	return FString();
}

FString FBaseStruct::ClassName()
{
	return FString();
}

FString FBaseStruct::VariableName()
{
	return FString();
}

FString FBaseStruct::DisplayName()
{
	return FString();
}

FString FBaseStruct::Conditions()
{
	return FString();
}

FBaseStruct::~FBaseStruct()
{

}

FString FBaseStruct::OpenBrakets(int tabCount)
{
	return FString();
}

FString FBaseStruct::ClosedBraketsComma(int tabCount)
{
	return FString();
}

FString FBaseStruct::ClosedBrakets(int tabCount)
{
	return FString();
}

FString FBaseStruct::ClosedBraketSemiColon(int tabCount)
{
	return FString();
}

FString FBaseStruct::ContainerOpen(int tabCount)
{
	return FString();
}


FClothingItem::FClothingItem()
{
	bDisplayClassName = true;
	bDisplayDisplayName = true;
	bDisplayBuyPrice = true;
	bDisplayConditions = true;
}

FString FClothingItem::MakeString(bool isEndString)
{
	FString endString = !isEndString ? ClosedBraketsComma(0) : ClosedBrakets(0);
	return OpenBrakets(0) + ClassName() + Comma() + DisplayName() + Comma() + BuyPrice() + Comma() + Conditions() + endString;
}

FContainer::FContainer(FName name)
{
	_ContainerName = name;
}

FContainer::FContainer()
{

}

FString FContainer::MakeString(bool isEndString)
{
return FString();
}

FString FVirtualItem::MakeString(bool isEndString)
{
	return FString();
}

FString FVirtualItem::Weight()
{
	return FString();
}

FString FVirtualItem::Illegal()
{
	return FString();
}

FString FVirtualItem::Edible()
{
	return FString();
}

FString FVirtualItem::Drinkable()
{
	return FString();
}

FString FVirtualItem::Icon()
{
	return FString();
}

FConfigClothing::FConfigClothing()
{

}

FString FConfigClothing::MakeString()
{
	return FString();
}

FString FItemBase::MakeString(bool isEndString)
{
	return FString();
}

FString FItemBase::BuyPrice()
{
	return FString();
}

FString FItemBase::SellPrice()
{
	return FString();
}

FConfigBase::~FConfigBase()
{

}

FString FConfigBase::MakeString()
{
	return FString();
}
