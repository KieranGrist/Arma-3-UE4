#include "../Public/WeaponItem.h"

FString UWeaponItem::MakeString(bool isEndString)
{
	FString ret;
	ret += OpenBrakets(2);
		ret += ClassName();
		ret += NickName();
		ret += BuyPrice();
		ret += SellPrice();
		ret += Conditions();
		ret += ClosedBrakets(0) + Comma(isEndString);
		return ret;
}

FString UWeaponItem::ClassName()
{
	return Tab() + Quote() + _ClassName.ToString() + Quote() + Comma(true);
}

FString UWeaponItem::NickName()
{
	return Quote() + _NickName + Quote() + Comma(true) ;
}

FString UWeaponItem::BuyPrice()
{
	return FString::FromInt(_BuyPrice) + Comma(true);
}

FString UWeaponItem::SellPrice()
{
	return FString::FromInt(_SellPrice) + Comma(true);
}

FString UWeaponItem::Conditions()
{
	return Quote() + _Conditions + Quote() + Comma(true);
}


void UWeaponItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
