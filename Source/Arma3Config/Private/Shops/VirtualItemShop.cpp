#include "Shops/VirtualItemShop.h"


FString UVirtualItemShop::ClassName()
{
	return ClassString(_ClassName.ToString(), _ClassTabs);
}

FString UVirtualItemShop::ShopName()
{
	return ClassMember("name", _ClassTabs, _ShopName.ToString());
}

FString UVirtualItemShop::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Conditions);
}

FString UVirtualItemShop::Side()
{
	return ClassMember("side", _ClassMembersTabs, _Conditions);
}

FString UVirtualItemShop::Items()
{
	return ClassMember("items", _ClassMembersTabs, _Items);
}

FString UVirtualItemShop::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += ShopName();
	ret += Conditions();
	ret += Side();
	ret += Items();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UVirtualItemShop::UpdateConfigText()
{
	_ConfigText = MakeString();
}
