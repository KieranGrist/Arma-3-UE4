// Fill out your copyright notice in the Description page of Project Settings.
#include "ClothingShop.h"
#include "ClothingItem.h"

FString UClothingShop::ClassName()
{
	return ClassString(_ShopName.ToString(), _ClassTabs);
}

FString UClothingShop::ShopName()
{
	return ClassMember("title", _ClassTabs, _ShopName.ToString());
}

FString UClothingShop::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString UClothingShop::Side()
{
	return ClassMember("side", _ClassMembersTabs, _Conditions);
}

FString UClothingShop::Uniforms()
{
	return ClassMember("uniforms", _ClassMembersTabs, _Uniforms);
}

FString UClothingShop::Headgear()
{
	return ClassMember("headgear", _ClassMembersTabs, _Uniforms);	
}

FString UClothingShop::Goggles()
{
	return ClassMember("headgear", _ClassMembersTabs, _Uniforms);	
}

FString UClothingShop::Vests()
{
	return ClassMember("headgear", _ClassMembersTabs, _Uniforms);	
}

FString UClothingShop::Backpacks()
{
	return ClassMember("headgear", _ClassMembersTabs, _Uniforms);	
}

FString UClothingShop::MakeString()
{
	FString ret;
	_ClassMembersTabs = _ClassTabs + 1;
	ret += ClassName();
	ret += ShopName();
	ret += Conditions();
	ret += Side();
	ret += Uniforms();
	ret += Headgear();
	ret += Goggles();
	ret += Vests();
	ret += Backpacks();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UClothingShop::UpdateConfigText()
{
	_ConfigText = MakeString();
}