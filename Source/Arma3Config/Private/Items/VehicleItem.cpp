#include "Items/VehicleItem.h"


FString UVehicleItem::ClassName()
{
	return ClassString(_ClassName.ToString(), _ClassTabs);
}

FString UVehicleItem::VirtualItemSpace()
{
	return ClassMember("vItemSpace", _ClassMembersTabs, _VirtualItemSpace);
}

FString UVehicleItem::Conditions()
{
	return ClassMember("conditions", _ClassMembersTabs, _Condition);
}

FString UVehicleItem::Price()
{
	return ClassMember("price", _ClassMembersTabs, _Price);
}

FString UVehicleItem::VehicleTextures()
{
	FString ret = Tab(_ClassMembersTabs) + "textures" + ContainerOpen();
	for (int i =0; i < _VehicleTextures.Num(); i++)
	{
		ret +=_VehicleTextures[i].MakeString(_ClassMembersTabs, i < _VehicleTextures.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}


FString UVehicleItem::MakeString(bool isEndString)
{
	FString ret;
	ret += OpenBrackets();
	ret += ClassName();
	ret += VirtualItemSpace();
	ret += Conditions();
	ret += Price();
	ret += VehicleTextures();
	return ret;
}

void UVehicleItem::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}

FString FVehicleTexture::MakeString(int classMemberTabs, bool useComma)
{
	classMemberTabs++;

	FString ret = UItemBase::OpenBrackets(classMemberTabs);
	ret += UItemBase::Quote();
	ret += _TextureName.ToString();
	ret += UItemBase::Comma(true);
	ret += UItemBase::Quote();
	ret += UItemBase::Side(_Side);
	ret += UItemBase::Quote();
	ret += UItemBase::Comma(true);
	ret += UItemBase::NewLine();
	ret += UItemBase::OpenBrackets(classMemberTabs + 1);
	for (int i = 0; i < _TexturePaths.Num(); i++)
	{
		ret += UItemBase::Tab(classMemberTabs + 2);
		ret += UItemBase::Quote();
		ret += _TexturePaths[i];
		ret += UItemBase::Quote();
		ret += UItemBase::NewLine();
	}
	ret += UItemBase::ClosedBracketsComma(classMemberTabs + 1);
	ret += UItemBase::Quote();
	ret += _Conditions;
	ret += UItemBase::Quote();
	ret += UItemBase::ClosedBrackets(0);
	ret += UItemBase::Comma(useComma);
	return ret;
}
