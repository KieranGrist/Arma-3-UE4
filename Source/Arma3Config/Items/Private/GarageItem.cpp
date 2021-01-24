#include "../Public/GarageItem.h"

// Sets default values
FString UGarageItem::MakeString(bool isEndString)
{
	FString ret = ClassName();
	ret += ClassName();
	ret += GarageSpawnPosition();
	ret += GarageSpawnDirection();
	ret += GarageBlacklist();
	return ret;
}

void UGarageItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}

FString UGarageItem::ClassName()
{
	return ClassString(_ClassName.ToString(), _ClassTabs);
}

FString UGarageItem::Price()
{
	return ClassMember("price", _ClassMembersTabs, _Price);
}

FString UGarageItem::GarageSpawnPosition()
{
	return ClassMember("garageSpawnPos", _ClassMembersTabs, _GarageSpawnPosition);
}

FString UGarageItem::GarageSpawnDirection()
{
	return ClassMember("garageSpawnDir", _ClassMembersTabs, _GarageSpawnDirection);
}

FString UGarageItem::GarageBlacklist()
{
	return 	ClassContainerMember("garageBlacklists", _ClassMembersTabs, _GarageBlacklist);
}
