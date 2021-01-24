#include "../Public/ClothingItem.h"

FString UClothingItem::MakeString(bool isEndString)
{
	FString ret;
	ret += OpenBrackets();
	ret += ClassName();
	ret += DisplayName();
	ret += Price();
	ret += Conditions();
	ret += ClosedBrackets(); 
	ret += Comma(isEndString);
	return ret;
}

FString UClothingItem::ClassName()
{  
	return LineClassName(_ClassName.ToString());
}

FString UClothingItem::DisplayName()
{
return LineMember(_DisplayName,true);
}

FString UClothingItem::Conditions()
{
	return LineMember(_Conditions, false);
}

FString UClothingItem::Price()
{
	return LineMember(_Price, true);
}

void UClothingItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
