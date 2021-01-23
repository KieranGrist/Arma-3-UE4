#include "../Public/ClothingItem.h"

FString UClothingItem::MakeString(bool isEndString)
{
	FString ret;
	ret += OpenBrakets(0);
	ret += ClassName();
	ret += DisplayName();
	ret += Price();
	ret += Conditions() +  ClosedBrakets(0) +  Comma(isEndString);
	return ret;
}

FString UClothingItem::ClassName()
{
	return Quote() + _ClassName.ToString() + Quote() + Comma(true);
}

FString UClothingItem::DisplayName()
{
	return Quote() + _DisplayName + Quote() + Comma(true);
}

FString UClothingItem::Conditions()
{
	return Quote() + _Conditions + Quote();
}

FString UClothingItem::Price()
{
	return FString::FromInt(_Price) + Comma(true);
}

void UClothingItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
