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
	return ret;
}

FString ULicenseItem::ClassName()
{
	return Tab() + "class " + _VariableName.ToString() + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString ULicenseItem::VariableName()
{
	return Tab() + "variable = " + Quote() + _VariableName.ToString() + Quote() + ClosedBraketSemiColon(0) + NewLine();
}

FString ULicenseItem::DisplayName()
{
	return Tab() + "displayName = " + Quote() + _DisplayName.ToString() + Quote() + ClosedBraketSemiColon(0) + NewLine();
}

FString ULicenseItem::Price()
{
	return Tab() + "price =" + FString::FromInt(_Price) + ClosedBraketSemiColon(0) + NewLine();
}

FString ULicenseItem::LicenseIllegal()
{
	return Tab() + "illegal =" + BoolToString(_LicenseIllegal) + ClosedBraketSemiColon(0) + NewLine();
}

FString ULicenseItem::LicenseSide()
{

	return Tab() + "side =" + Side(_LicenseSide) + ClosedBraketSemiColon(0) + NewLine() + ClosedBraketSemiColon(1);
}

void ULicenseItem::UpdateConfigText()
{
	_ConfigText = MakeString();
}
