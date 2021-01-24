#include "MineralItem.h"
#include "VirtualItem.h"

FString UMineralItem::ClassName()
{
	return ClassString(_ClassName, _ClassTabs);
}

FString UMineralItem::Amount()
{
	return ClassMember("amount", _ClassMembersTabs, _Amount);
}

FString UMineralItem::Zones()
{
	return ClassMember("zones", _ClassMembersTabs, _Zones);
}

FString UMineralItem::Item()
{
	return ClassMember("item", _ClassMembersTabs, _Item);
}

FString UMineralItem::Mined()
{
 return ClassMember("mined", _ClassMembersTabs, _ItemMined);
 }
FString UMineralItem::ZoneSize()
{
	return ClassMember("zoneSize", _ClassMembersTabs, _ZoneSize);
}

FString UMineralItem::MakeString()
{
	FString ret;
	if (!_ItemMined.Num() ==0)
	{
		return "No item has been set up, please fix";
	}
	ret += ClassName();
	ret += Amount();
	ret += Zones();
	ret += Item();
	ret += Mined();
	ret += ZoneSize();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UMineralItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
