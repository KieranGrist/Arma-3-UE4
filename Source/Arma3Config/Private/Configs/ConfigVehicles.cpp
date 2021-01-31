#include "Configs/ConfigVehicles.h"
#include "Shops/VehicleShop.h"

FString UConfigVehicles::MakeString()
{
	FString ret = ClassString("Clothing", _ClassTabs);
	for (UVehicleShop* shop : _Shops)
	{
		shop->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigVehicles::UpdateConfigText()
{
	_ConfigText = MakeString();
}
