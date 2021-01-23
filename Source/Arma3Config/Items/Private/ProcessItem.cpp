#include "../Public/ProcessItem.h"
#include "../Public/VirtualItem.h"

FString UProcessItem::ClassName()
{
	return Tab() + "class " + _ClassName + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UProcessItem::MaterialsRequired()
{
	FString ret = Tab() + "MaterialsReq[] = {";
	int mapCount = _MaterialsRequired.Num();
	int index = 0;
	for (auto& Elem : _MaterialsRequired)
	{	
		ret += OpenBrakets(0) + Quote() + Elem.Key->_VariableName.ToString() + Quote() + Comma(true) + FString::FromInt(Elem.Value) + ClosedBrakets(0) + Comma(index < mapCount);
		index++;
	}
	ret += ClosedBraketSemiColon(0) + NewLine();
	return ret;
}

FString UProcessItem::MaterialsGiven()
{
	FString ret = Tab() + "MaterialsGive[] = {";
	ret += OpenBrakets(0) + Quote() + _MaterialsGiven.Key->_VariableName.ToString() + Quote() + Comma(true) + FString::FromInt(_MaterialsGiven.Value) + ClosedBrakets(0);
	ret += ClosedBraketSemiColon(0) + NewLine();
	return ret;
}

FString UProcessItem::ProgressBarText()
{
	return Tab() + "Text = " + Quote() + _ProgressBarText + Quote() + SemiColon(0) + NewLine();
}

FString UProcessItem::NoLicenseCost()
{
	return "NoLicenseCost = " + FString::FromInt(_NoLicenseCost) + ";" + NewLine() + ClosedBraketSemiColon(1);
}

FString UProcessItem::MakeString(bool isEndString)
{
	FString ret;
	if (!_MaterialsRequired.Num() == 0 )
	{
		return "No item has been set up, please fix";
	}
	ret += ClassName();
	ret += MaterialsRequired();
	ret += MaterialsGiven();
	ret += ProgressBarText();
	ret += NoLicenseCost();
	return ret;
}

void UProcessItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
