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
	return Tab() + "class " + _ClassName.ToString() + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UGarageItem::Price()
{
	return Tab() + " price = " + FString::FromInt(_Price) + SemiColon(0) + NewLine();
}

FString UGarageItem::GarageSpawnPosition()
{
	return Tab() + "garageSpawnPos[] = {" + _GarageSpawnPosition.ToString() + ClosedBraketSemiColon(0) + NewLine();
}

FString UGarageItem::GarageSpawnDirection()
{
	return Tab() + "garageSpawnDir =" + FString::FromInt(_GarageSpawnDirection) + SemiColon(0) + NewLine();
}

FString UGarageItem::GarageBlacklist()
{

	FString ret = Tab() + "garageBlacklists[] = {" + NewLine();
	for (const auto garageBlacklist : _GarageBlacklists)
	{
		ret += "{" + garageBlacklist.ToString() + ClosedBraketsComma(0);
	}
	ret += NewLine() + ClosedBraketSemiColon(1);
	return ret;
}
