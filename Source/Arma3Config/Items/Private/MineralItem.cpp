#include "../Public/MineralItem.h"
#include "../Public/VirtualItem.h"

FString UMineralItem::ClassName()
{
	return Tab() + "class " + _ClassName + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UMineralItem::Amount()
{
	return Tab() + "amount = " + FString::FromInt(_Amount) + SemiColon(1);
}

FString UMineralItem::Zones()
{
	FString ret = Tab() + "zones[] = {";
	int index =0;
	for (const auto zone : _Zones)
	{
		ret += Quote() + zone + Quote() + Comma(index < _Zones.Num());
		index++;
	}
	ret += ClosedBraketSemiColon(1);
	return ret;
}

FString UMineralItem::Item()
{
	FString ret = Tab() + "item = " + Quote();
	if (_Item)
	{
		ret += _Item->_VariableName.ToString();
	}
	ret += Quote() + ";" + NewLine();
	return ret;
}

FString UMineralItem::Mined()
{
	FString ret = Tab() + "mined[] = {";
	for (const auto mined : _ItemMined)
	{
		ret += Quote() + mined->_VariableName.ToString() + Quote();
	}
	ret += ClosedBraketSemiColon(1);
	return ret;
}

FString UMineralItem::ZoneSize()
{
	return Tab() +  "zoneSize = " + FString::FromInt(_ZoneSize) + ";" + NewLine() + SemiColon(0) + ClosedBraketSemiColon(1);
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
	return ret;
}

void UMineralItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
