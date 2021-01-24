// Fill out your copyright notice in the Description page of Project Settings.
#include "ClothingShop.h"
#include "../Items/Public/ClothingItem.h"

FString UClothingShop::ShopName()
{
	return ClassString(_ShopName.ToString(), _ClassTabs);
}

FString UClothingShop::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString UClothingShop::Side()
{
	return FString();
}

FString UClothingShop::Uniforms()
{
	return FString();
}

FString UClothingShop::Headgear()
{
	return FString();
}

FString UClothingShop::Goggles()
{
	return FString();
}

FString UClothingShop::Vests()
{
	return FString();
}

FString UClothingShop::Backpacks()
{
	return FString();
}

FString UClothingShop::MakeString()
{
	return FString();
}

void UClothingShop::UpdateConfigText()
{

}
