// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/ItemBase.h"

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
	return tabs + "};";
}

FString UItemBase::SemiColon(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab();
	}
	return tabs + ";";
}

FString UItemBase::ContainerOpen(int tabCount)
{
	return "[] = " + NewLine() + OpenBrakets(tabCount);
}