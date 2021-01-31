#include "Configs/ConfigWeapons.h"
#include "Shops/WeaponShop.h"

FString UConfigWeapons::MakeString()
{
	FString ret = ClassString("WeaponShops", _ClassTabs);
	for (UWeaponShop* shop : _Shops)
	{
		shop->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigWeapons::UpdateConfigText()
{
	_ConfigText = MakeString();
}
