#include "Items/ResourceItem.h"
#include "Items/VirtualItem.h"

FString UResourceItem::ClassName()
{
	return ClassString(_ItemGathered->_VItem._VariableName.ToString(), _ClassTabs);
}

FString UResourceItem::Amount()
{
	return ClassMember("amount", _ClassMembersTabs, _Amount);
}

FString UResourceItem::Zones()
{
	return ClassMember("zones", _ClassMembersTabs, _Zones);
}

FString UResourceItem::Item()
{
	return ClassMember("item", _ClassMembersTabs, _Item);
}

FString UResourceItem::ZoneSize()
{
	return ClassMember("zoneSize", _ClassMembersTabs, _ZoneSize);
}

FString UResourceItem::MakeString()
{
	FString ret;
	if (!_ItemGathered)
	{
		return "No item has been set up, please fix";
	}
	ret += ClassName();
	ret += Amount();
	ret += Zones();
	ret += Item();
	ret += ZoneSize();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

void UResourceItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
