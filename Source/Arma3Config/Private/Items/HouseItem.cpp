#include "Items/HouseItem.h"

// Sets default values
FString UHouseItem::MakeString()
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
	_ConfigText = MakeString();
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
	return ClassMember("restrictedPos", _ClassMembersTabs, _RestrictedPositions);
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
	return ClassMember("garageBlacklists", _ClassMembersTabs, _GarageBlacklist);
}

FString UHouseItem::LightPosition()
{
	return ClassMember("lightPos", _ClassMembersTabs, _LightPosition);
}
