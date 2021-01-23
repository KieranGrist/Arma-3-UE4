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
	return ret;
}

void UHouseItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}

FString UHouseItem::ClassName()
{
	return Tab() + "class " + _ClassName.ToString() + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UHouseItem::Price()
{
	return Tab() + " price = " + FString::FromInt(_Price) + SemiColon(0) + NewLine();
}

FString UHouseItem::NumberOfCrates()
{
	return Tab() + " numberCrates = " + FString::FromInt(_NumberOfCrates) + ";" + NewLine();
}

FString UHouseItem::RestrictedPositions()
{
	FString ret = "restrictedPos[] = {";
	int index =0;
	for (const auto restrictedPosition : _RestrictedPositions)
	{
		ret +=  FString::FromInt(restrictedPosition) + Comma(index < _RestrictedPositions.Num());
		index ++;
	}
	ret += NewLine() + ClosedBraketSemiColon(1);
	return ret;
}

FString UHouseItem::CanGarage()
{
	return "canGarage" + _CanGarage + NewLine() + ClosedBraketSemiColon(1);
}

FString UHouseItem::GarageSpawnPosition()
{
	if (_GarageSpawnPosition.IsZero())
	{
		return Tab() + "garageSpawnPos[] = {" + ClosedBraketSemiColon(0) + NewLine();
}
	return Tab() + "garageSpawnPos[] = {" + _GarageSpawnPosition.ToString() + ClosedBraketSemiColon(0) + NewLine();
}


FString UHouseItem::GarageSpawnDirection()
{
	return Tab() + "garageSpawnDir = " + FString::FromInt(_GarageSpawnDirection) +SemiColon(0) + NewLine();
}

FString UHouseItem::GarageBlacklist()
{
	FString ret = Tab() + "garageBlacklists[] = {" + NewLine();
	for (const auto garageBlacklist : _GarageBlacklists)
	{
		ret += "{" + garageBlacklist.ToString() + ClosedBraketsComma(0) ;
	}
	ret += NewLine() + ClosedBraketSemiColon(1);
	return ret;
}

FString UHouseItem::LightPosition()
{
	return Tab() + "lightPos[] = {" + _GarageSpawnPosition.ToString() + ClosedBraketSemiColon(0) + NewLine() + ClosedBraketSemiColon(1);
}
