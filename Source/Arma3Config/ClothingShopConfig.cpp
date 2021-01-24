// Fill out your copyright notice in the Description page of Project Settings.


#include "ClothingShopConfig.h"

FString UClothingShopConfig::MakeString()
{
	FString shopsStrings;
	for (int i = 0; i < _ClothingShops.Num(); i++)
	{
		shopsStrings += _ClothingShops[i]->MakeString();
	}
	return "class " + _ClassName.ToString() + UItemBase::NewLine() + UItemBase::OpenBrackets() + shopsStrings + UItemBase::ClosedBracketSemiColon();
}
