#include "../Public/WeaponItem.h"

FString UWeaponItem::MakeString(bool isEndString)
{
	FString ret;
	ret += OpenBrackets(2);
	ret += ClassName();
	ret += NickName();
	ret += BuyPrice();
	ret += SellPrice();
	ret += Conditions();
	ret += ClosedBrackets() + Comma(isEndString);
	return ret;
}

FString UWeaponItem::ClassName()
{
	return LineClassName(_ClassName.ToString());
}

FString UWeaponItem::NickName()
{
	return LineMember(_NickName, true);
}

FString UWeaponItem::BuyPrice()
{
	return LineMember(_BuyPrice, true);
}

FString UWeaponItem::SellPrice()
{
	return LineMember(_SellPrice, true);
}

FString UWeaponItem::Conditions()
{
	return LineMember(_Conditions, false);
}


void UWeaponItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
