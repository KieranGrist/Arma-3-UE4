// Fill out your copyright notice in the Description page of Project Settings.
#include "ItemBase.h"

// Sets default values
UItemBase::UItemBase()
{

}

FString UItemBase::OpenBrakets(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab();
	}
	return tabs + "{ ";
}

FString UItemBase::ClosedBraketsComma(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab();
	}
	return tabs + "},";
}

FString UItemBase::ClosedBrakets(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab();
	}
	return tabs + "}";
}

FString UItemBase::ClosedBraketSemiColon(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab();
	}
	return NewLine() + tabs + "};";
}

FString UItemBase::ContainerOpen(int tabCount)
{
	return "[] = " + NewLine() + OpenBrakets(tabCount);
}

FString UItemBase::MakeString(bool isEndString)
{
	FString ret;
	if (bDisplayClassName)
	{
		ret += ClassName();
	}

	if (bDisplayVariableName)
	{
		ret += VariableName();
		ret += Comma();
	}

	if (bDisplayDisplayName)
	{
		ret += DisplayName();
		ret += Comma();
	}

	if (bDisplayBuyPrice)
	{
		ret += BuyPrice();
		ret += Comma();
	}

	if (bDisplaySellPrice)
	{
		ret += SellPrice();
		ret += Comma();
	}

	if (bDisplayConditions)
	{
		ret += Conditions();
	}


	return ret;
}

FString UItemBase::ClassName()
{
	return Tab() + "class " + _ClassName.ToString() + Tab() + NewLine() + OpenBrakets(1) + NewLine();
}

FString UItemBase::VariableName()
{
	return Quote() + _VariableName.ToString() + Quote();
}

FString UItemBase::DisplayName()
{
	return Quote() + _DisplayName + Quote();
}

FString UItemBase::Conditions()
{
	return Quote() + _Conditions + Quote();
}

FString UItemBase::BuyPrice()
{
	return  FString::FromInt(_BuyPrice);
}

FString UItemBase::SellPrice()
{
	return  FString::FromInt(_SellPrice);
}

void UItemBase::UpdateConfigText()
{
	_ConfigText = MakeString(false);
}
