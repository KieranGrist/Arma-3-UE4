#include "Configs/ConfigClothing.h"
#include "Shops/ClothingShop.h"


FString UConfigClothing::MakeString()
{
	FString ret = ClassString("Clothing", _ClassTabs);
	for (auto shop : _Shops)
	{
		shop->_ClassTabs = _ClassTabs + 1;
		ret += shop->MakeString();
	}
	ret += NewLine() + ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UConfigClothing::UpdateConfigText()
{
	_ConfigText = MakeString();
}
