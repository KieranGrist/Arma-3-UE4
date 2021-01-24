#include "../Public/ResourceItem.h"
#include "../Public/VirtualItem.h"

FString UResoruceItem::ClassName()
{
	return ClassString(_ItemGathered->_VariableName.ToString(), _ClassTabs);
}

FString UResoruceItem::Amount()
{
	return ClassMember("amount", _ClassMembersTabs, _Amount);
}

FString UResoruceItem::Zones()
{
	return ClassContainerMember("zones", _ClassMembersTabs, _Zones);
}

FString UResoruceItem::Item()
{
	return ClassMember("item", _ClassMembersTabs, _Item);
}

FString UResoruceItem::ZoneSize()
{
	return ClassMember("zoneSize", _ClassMembersTabs, _ZoneSize);
}

FString UResoruceItem::MakeString(bool isEndString)
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

void UResoruceItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
