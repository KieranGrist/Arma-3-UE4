#include "Configs/ConfigGarages.h"
#include "Items/GarageItem.h"


FString UConfigGarages::MakeString()
{
	FString ret = ClassString("Garages", _ClassTabs);
	ret += ClassString(MapName(), _ClassTabs);
	for (UGarageItem* item : _GarageItems)
	{
		ret += item->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigGarages::UpdateConfigText()
{
	_ConfigText = MakeString();
}
