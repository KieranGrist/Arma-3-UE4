#include "Configs/ConfigSpawnPoints.h"
#include "Items/SpawnItem.h"

FString UConfigSpawnPoints::MakeString()
{
	FString ret = ClassString("CfgSpawnPoints", _ClassTabs);
	ret += ClassString(MapName(), _ClassTabs);

	ret += ClassString("Civilian", _ClassTabs);
	for (USpawnItem* item : _CivlianSpawns)
	{
		ret += item->MakeString();
	}


	ret += ClassString("Cop", _ClassTabs);
	for (USpawnItem* item : _CopSpawns)
	{
		ret += item->MakeString();
	}

	ret += ClassString("Medic", _ClassTabs);
	for (USpawnItem* item : _MedicSpawns)
	{
		ret += item->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigSpawnPoints::UpdateConfigText()
{
	_ConfigText = MakeString();
}
