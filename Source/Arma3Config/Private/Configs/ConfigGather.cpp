#include "Configs/ConfigGather.h"
#include "Items/ResourceItem.h"
#include "Items/MineralItem.h"



FString UConfigGather::MakeString()
{
	FString ret = ClassString("CfgGather", _ClassTabs);
	ret += ClassString("Resources", _ClassTabs);
	for (UResourceItem* item : _Resources)
	{
		item->MakeString();
	}
	ret += ClassString("Minerals", _ClassTabs);
	for (UMineralItem* item : _Minerals)
	{
		item->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigGather ::UpdateConfigText()
{
	_ConfigText = MakeString();
}
