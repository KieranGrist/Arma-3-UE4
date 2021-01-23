// Fill out your copyright notice in the Description page of Project Settings.
#include "ShopBase.h"

FString UShopBase::ClassName()
{
	return UItemBase::Tab() + "class " + _ClassName.ToString() + UItemBase::Tab() + UItemBase::NewLine() + UItemBase::OpenBrakets(1) + UItemBase::NewLine();
}

FString UShopBase::ShopName()
{
	return UItemBase::Quote() + _ShopName.ToString() + UItemBase::Quote();
}

FString UShopBase::Conditions()
{
	return 	UItemBase::Tab() + UItemBase::Tab() + "conditions = " + _Conditions + UItemBase::NewLine();
}

FString UShopBase::Containers()
{
	FString containerText;
	return containerText;
}

void UShopBase::UpdateConfigText()
{
	_ConfigText = MakeString();
}

FString UShopBase::MakeString()
{
	FString ret;
		ret += ClassName();
		ret += ShopName();
		ret += Side();
		ret += Conditions();
		return ret;
}


FString UShopBase::Side()
{
	return UItemBase::Tab() + UItemBase::Tab() + "side = " + _Side + ";" + UItemBase::NewLine();
}