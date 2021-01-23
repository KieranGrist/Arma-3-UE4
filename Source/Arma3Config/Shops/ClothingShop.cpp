// Fill out your copyright notice in the Description page of Project Settings.
#include "ClothingShop.h"
#include "../Items/Public/ClothingItem.h"


// Sets default values for this component's properties
UClothingShop::UClothingShop()
{
	_ShopName = "ClothingShop";
	_Containers.Emplace(FClothingShopContainer("uniforms"));
	_Containers.Emplace(FClothingShopContainer("headgear"));
	_Containers.Emplace(FClothingShopContainer("goggles"));
	_Containers.Emplace(FClothingShopContainer("vests"));
	_Containers.Emplace(FClothingShopContainer("backpacks"));
}

FClothingShopContainer::FClothingShopContainer()
{

}

FClothingShopContainer::FClothingShopContainer(FName name)
{
	_ContainerName = name;
}

FString FClothingShopContainer::MakeString()
{
	FString containerString = "";
	for (int i = 0; i < _ContainerItems.Num(); i++)
	{
		containerString += _ContainerItems[i]->MakeString(i == _ContainerItems.Num() - 1);
	}
	return _ContainerName.ToString() + UItemBase::ContainerOpen(2) + containerString + UItemBase::ClosedBraketSemiColon(2);
}

void FClothingShopContainer::UpdateConfigText()
{
	_ConfigText = MakeString();
}