#include "ConfigClothing.h"
#include "ClothingShop.h"


FString UConfigClothing::MakeString()
{
	FString ret = ClassString("Clothing", _ClassTabs);
	for (auto shop : _Shops)
	{
		ret += shop->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigClothing::UpdateConfigText()
{
	_ConfigText = MakeString();
}
