#include "../Public/HouseItem.h"

// Sets default values
FString UHouseItem::MakeString(bool isEndString)
{
	FString ret = ClassName();
	ret += Price();
	ret += NumberOfCrates();
	ret += RestrictedPositions();
	ret += CanGarage();
	ret += GarageSpawnPosition();
	ret += GarageSpawnDirection();
	ret += GarageBlacklist();
	ret += LightPosition();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UHouseItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}

FString UHouseItem::ClassName()
{
	return ClassString(_ClassName.ToString(), _ClassTabs);
}

FString UHouseItem::Price()
{
	return ClassMember("price", _ClassMembersTabs, _Price);
}

FString UHouseItem::NumberOfCrates()
{
	return ClassMember("numberCrates", _ClassMembersTabs, _NumberOfCrates);
}

FString UHouseItem::RestrictedPositions()
{
	return ClassContainerMember("restrictedPos", _ClassMembersTabs, _RestrictedPositions);
 }
FString UHouseItem::CanGarage()
{
	return ClassMember("canGarage", _ClassMembersTabs, _CanGarage);
}

FString UHouseItem::GarageSpawnPosition()
{
	return ClassMember("garageSpawnPos", _ClassMembersTabs, _GarageSpawnPosition);
}

FString UHouseItem::GarageSpawnDirection()
{
	return ClassMember("garageSpawnDir", _ClassMembersTabs, _GarageSpawnDirection);
}

FString UHouseItem::GarageBlacklist()
{
	return ClassContainerMember("garageBlacklists", _ClassMembersTabs, _GarageBlacklist);
}

FString UHouseItem::LightPosition()
{
	return ClassMember("lightPos", _ClassMembersTabs, _LightPosition);
}
