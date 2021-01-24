// Fill out your copyright notice in the Description page of Project Settings.
#include "WeaponShop.h"


FString UWeaponShop::ClassName()
{
	return ClassString(_ShopName.ToString(), _ClassTabs);
}

FString UWeaponShop::ShopName()
{
	return ClassMember("title", _ClassTabs, _ShopName.ToString());
}

FString UWeaponShop::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString UWeaponShop::Side()
{
	return ClassMember("side", _ClassMembersTabs, _Conditions);
}

FString UWeaponShop::Weapons()
{
	return ClassMember("items", _ClassMembersTabs, _Weapons);
}

FString UWeaponShop::Magazines()
{
	return ClassMember("mags", _ClassMembersTabs, _Magazines);
}

FString UWeaponShop::Accessories()
{
	return ClassMember("accs", _ClassMembersTabs, _Accessories);
}

FString UWeaponShop::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += ShopName();
	ret += Conditions();
	ret += Weapons();
	ret += Magazines();
	ret += Accessories();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UWeaponShop::UpdateConfigText()
{
	_ConfigText = MakeString();
}
