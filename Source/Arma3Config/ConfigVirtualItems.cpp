#include "ConfigVirtualItems.h"
#include "VirtualItemShop.h"

FString UConfigVirtualItems::MakeString()
{
	FString ret = ClassString("VirtualShops", _ClassTabs);
	for (UVirtualItemShop* shop : _Shops)
	{
		ret += shop->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigVirtualItems::UpdateConfigText()
{
	_ConfigText = MakeString();
}
