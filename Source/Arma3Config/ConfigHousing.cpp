#include "ConfigHousing.h"
#include "HouseItem.h"

FString UConfigHousing::MakeString()
{
	FString ret = ClassString("Housing", _ClassTabs);
	ret += ClassString(MapName(), _ClassTabs);
	for (UHouseItem* item : _HouseItems)
	{
		ret += item->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigHousing::UpdateConfigText()
{
	_ConfigText = MakeString();
}
