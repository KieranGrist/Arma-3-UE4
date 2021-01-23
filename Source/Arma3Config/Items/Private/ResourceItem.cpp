#include "../Public/ResourceItem.h"
#include "../Public/VirtualItem.h"

FString UResoruceItem::ClassName()
{
	return Tab() + "class " + _ItemGathered->_VariableName.ToString() + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UResoruceItem::Amount()
{
	return Tab() + "amount = " + FString::FromInt(_Amount) + ClosedBrakets(0) + NewLine();
}

FString UResoruceItem::Zones()
{
	FString ret = "zones[] = {";
	int index =0;
	for (const auto zone : _Zones)
	{
		ret += Quote() + zone + Quote() + Comma(index < _Zones.Num());
		index++;
	}
	ret += ClosedBraketSemiColon(0);
	return ret;
}

FString UResoruceItem::Item()
{
	FString ret = Tab() + "item = " + Quote();
	if (_Item)
	{
		ret += _Item->_VariableName.ToString();
	}
	ret += Quote() + ";";
	return ret;
}

FString UResoruceItem::ZoneSize()
{
	return Tab() + "zoneSize = " + FString::FromInt(_ZoneSize) + SemiColon(0) + NewLine() + ClosedBraketSemiColon(1);
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
	return ret;
}

void UResoruceItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
