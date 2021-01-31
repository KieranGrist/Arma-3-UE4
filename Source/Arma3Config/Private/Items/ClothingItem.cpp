#include "Items/ClothingItem.h"

FString FClothingItemConfig::MakeString(bool isEndString)
{
	FString ret;
	ret += ClassName();
	ret += DisplayName();
	ret += Price();
	ret += Conditions();
	ret += UClothingItem::ClosedBrackets();
	ret += UClothingItem::Comma(isEndString);
	return ret;
}

FString FClothingItemConfig::ClassName()
{  
	return UClothingItem::LineClassName(_ClassName.ToString());
}

FString FClothingItemConfig::DisplayName()
{
return UClothingItem::LineMember(_DisplayName,true);
}

FString FClothingItemConfig::Conditions()
{
	return UClothingItem::LineMember(_Conditions, false);
}

FString FClothingItemConfig::Price()
{
	return UClothingItem::LineMember(_Price, true);
}

void UClothingItem::UpdateConfigText()
{
	_ConfigText = _ClothingItem.MakeString(false);
}
