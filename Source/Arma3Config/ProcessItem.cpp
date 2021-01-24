#include "ProcessItem.h"
#include "VirtualItem.h"

FString UProcessItem::ClassName()
{
	return ClassString(_ClassName, _ClassTabs);
}

FString UProcessItem::MaterialsRequired()
{
	return VirtualMapToString("MaterialsReq", _ClassMembersTabs, _MaterialsRequired);;
}

FString UProcessItem::MaterialsGiven()
{	
	TArray<FString> materialsGiven = { VirtualPairToString(_MaterialsGiven, false) };
	return ClassMember("MaterialsGive", _ClassMembersTabs, materialsGiven);
}

FString UProcessItem::ProgressBarText()
{
	return ClassMember("Text", _ClassMembersTabs, _ProgressBarText);
}

FString UProcessItem::NoLicenseCost()
{
	return ClassMember("NoLicenseCost", _ClassMembersTabs, _NoLicenseCost);
}

FString UProcessItem::MakeString()
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
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString UProcessItem::VirtualPairToString(TPair<UVirtualItem*, int> pair, bool useComma)
{  
	FString ret;
	ret += LineClassName(pair.Key->_VariableName.ToString());
	ret += LineMember(pair.Value, false);
	ret += ClosedBrackets() + Comma(useComma);
	return ret;
}

FString UProcessItem::VirtualMapToString(FString name, int classMemberTabs, TMap<UVirtualItem*, int> virtualItemMap)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	int i = 0;
	for (auto& Elem : virtualItemMap)
	{
		i++;
		ret += VirtualPairToString(Elem, i < virtualItemMap.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

void UProcessItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
