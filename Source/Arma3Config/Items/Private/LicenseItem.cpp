// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/LicenseItem.h"


FString ULicenseItem::MakeString()
{
	FString ret;
	ret += ClassName();
	ret += VariableName();
	ret += DisplayName();
	ret += Price();
	ret += LicenseIllegal();
	ret += LicenseSide();
	ret += ClosedBracketSemiColon(_ClassTabs);
	return ret;
}

FString ULicenseItem::ClassName()
{
	return ClassString(_VariableName.ToString(), _ClassTabs);
}

FString ULicenseItem::VariableName()
{	
	return ClassMember("variable", _ClassMembersTabs,_VariableName.ToString());
}

FString ULicenseItem::DisplayName()
{
	return ClassMember("displayName", _ClassMembersTabs, _DisplayName.ToString());
}

FString ULicenseItem::Price()
{
	return ClassMember("price", _ClassMembersTabs, _Price);
}

FString ULicenseItem::LicenseIllegal()
{
	return ClassMember("illegal", _ClassMembersTabs, _LicenseIllegal);
}

FString ULicenseItem::LicenseSide()
{
	return ClassMember("side", _ClassMembersTabs, _LicenseSide);
}

void ULicenseItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
