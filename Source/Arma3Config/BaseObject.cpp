// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseObject.h"

UBaseObject::UBaseObject()
{

}

FBaseStruct::FBaseStruct()
{
}

const FString FBaseStruct::MakeString(const bool isEndString) const
{
	return FString();
}

const FString FBaseStruct::ClassName() const
{
	return FString();
}

const FString FBaseStruct::VariableName() const
{
	return FString();
}

const FString FBaseStruct::DisplayName() const
{
	return FString();
}

const FString FBaseStruct::Conditions() const
{
	return FString();
}

FBaseStruct::~FBaseStruct()
{
}

const FString FBaseStruct::OpenBrakets(const int tabCount) const
{
	return FString();
}

const FString FBaseStruct::ClosedBraketsComma(const int tabCount) const
{
	return FString();
}

const FString FBaseStruct::ClosedBrakets(const int tabCount) const
{
	return FString();
}

const FString FBaseStruct::ClosedBraketSemiColon(const int tabCount) const
{
	return FString();
}

const FString FBaseStruct::ContainerOpen(const int tabCount) const
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

const FString FClothingItem::MakeString(const bool isEndString) const
{
	const FString endString = !isEndString ? ClosedBraketsComma(0) : ClosedBrakets(0);
	return OpenBrakets(0) + ClassName() + Comma() + DisplayName() + Comma() + BuyPrice() + Comma() + Conditions() + endString;
}

const FString FItemBase::MakeString(const bool isEndString) const
{
	return FString();
}

const FString FItemBase::BuyPrice() const
{
	return FString();
}

const FString FItemBase::SellPrice() const
{
	return FString();
}

const FString FVirtualItem::MakeString(const bool isEndString) const
{
	return FString();
}

const FString FVirtualItem::Weight() const
{
	return FString();
}

const FString FVirtualItem::Illegal() const
{
	return FString();
}

const FString FVirtualItem::Edible() const
{
	return FString();
}

const FString FVirtualItem::Drinkable() const
{
	return FString();
}

const FString FVirtualItem::Icon() const
{
	return FString();

}

FContainer::FContainer()
{

}


FContainer::FContainer(FName name)
{
bDisplayClassName = true;
_ClassName = name;
}

const FString FContainer::MakeString(const bool isEndString) const
{
	return FString();
}


FConfigClothing::FConfigClothing()
{

}


const FString FConfigClothing::MakeString(const bool isEndString) const
{
	return FString();
}

const FString FConfigGarages::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigGather::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigHousing::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigLicenses::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigLoadouts::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigProcess::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigSpawnPoints::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigVehicles::MakeString(const bool isEndString) const
{
	return FString();

}

const FString FConfigVirtualItems::MakeString(const bool isEndString) const
{
	return FString();
}

const FString FConfigWeaponShops::MakeString(const bool isEndString) const
{
	return FString();
}

const FString UClothingFShop::MakeString(const bool isEndString) const
{
	return FString();
}

AClothingShopNPC::AClothingShopNPC()
{
  _ClothingShop = CreateDefaultSubobject<UClothingFShop>(TEXT("ClothingShop"));

}
