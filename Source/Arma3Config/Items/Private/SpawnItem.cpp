#include "..\Public\SpawnItem.h"
FString USpawnItem::ClassName()
{
	return Tab() + "class " + _ClassName + OpenBrakets(1) + NewLine();
}

FString USpawnItem::DisplayName()
{
	return Tab() + "displayName = " + Quote() + _DisplayName + Quote() + ClosedBrakets(0);
}

FString USpawnItem::SpawnMarker()
{
	return Tab() + "spawnMarker = " + Quote() + _SpawnMarker + Quote() + ClosedBrakets(0);
}

FString USpawnItem::Icon()
{
	return Tab() + "icon = " + Quote() + _Icon + Quote() + ClosedBrakets(0);
}

FString USpawnItem::Conditions()
{
	return Tab() + "conditions = " + Quote() + _Conditions + Quote() + ClosedBrakets(0) + NewLine() + ClosedBraketSemiColon(1);
}

FString USpawnItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += DisplayName();
	ret += SpawnMarker();
	ret += Icon();
	ret += Conditions();
	return ret;
}

void USpawnItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
