#include "Items/SpawnItem.h"
FString USpawnItem::ClassName()
{
	return ClassString(_ClassName, _ClassTabs);
}

FString USpawnItem::DisplayName()
{
	return ClassMember("displayName", _ClassMembersTabs, _DisplayName);
}

FString USpawnItem::SpawnMarker()
{
	return ClassMember("spawnMarker", _ClassMembersTabs, _SpawnMarker);
}

FString USpawnItem::Icon()
{
	return ClassMember("icon", _ClassMembersTabs, _Icon);
}

FString USpawnItem::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString USpawnItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += DisplayName();
	ret += SpawnMarker();
	ret += Icon();
	ret += Conditions();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void USpawnItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
