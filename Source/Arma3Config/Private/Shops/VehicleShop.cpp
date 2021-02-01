// Fill out your copyright notice in the Description page of Project Settings.
#include "Shops/VehicleShop.h"

FString UVehicleShop::ClassName()
{
	return ClassString(_ShopName.ToString(), _ClassTabs);
}

FString UVehicleShop::ShopName()
{
	return ClassMember("title", _ClassTabs, _ShopName.ToString());
}

FString UVehicleShop::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString UVehicleShop::Side()
{
	return ClassMember("side", _ClassMembersTabs, _Conditions);
}

FString UVehicleShop::Vehicles()
{
	return ClassMember("vehicles", _ClassMembersTabs, _Vehicles);
}

FString UVehicleShop::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += ShopName();
	ret += Conditions();
	ret += Side();
	ret += Vehicles();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UVehicleShop::UpdateConfigText()
{
	_ConfigText = MakeString();
}
