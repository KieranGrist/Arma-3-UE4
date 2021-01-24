// Fill out your copyright notice in the Description page of Project Settings.
#include "ItemBase.h"
#include "VirtualItem.h"
#include "VehicleItem.h"
#include "ClothingItem.h"
#include "WeaponItem.h"


FString UItemBase::MapName()
{
	return "Malden";
}

FString UItemBase::Quote()
{
	return "\"";
}

FString UItemBase::NewLine()
{
	return "\n";
}

FString UItemBase::Comma(bool useComma)
{
	if (!useComma)
	{
		return "";
	}
	return ", ";
}

FString UItemBase::Tab(int tabCount)
{
	FString tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += "	";
	}
	return tabs;
}

FString UItemBase::Side(FSide side)
{
	switch (side)
	{
	case  FSide::civ:
		return Quote() + "civ" + Quote();
		break;
	case FSide::cop:
		return Quote() + "cop" + Quote();
		break;
	case  FSide::med:
		return Quote() + "med" + Quote();
		break;
	}
	return "Error no side";
}

FString UItemBase::BoolToString(bool inBool)
{
	return inBool ? "true" : "false";
}

FString UItemBase::OpenBrackets(int tabCount)
{
	return Tab(tabCount) + "{ ";
}

FString UItemBase::ClosedBracketsComma(int tabCount )
{

	return Tab(tabCount) + "},";
}

FString UItemBase::ClosedBrackets(int tabCount)
{
	return Tab(tabCount) + "}";
}

FString UItemBase::ClosedBracketSemiColon(int tabCount)
{
	return Tab(tabCount) + "};";
}

FString UItemBase::SemiColon(int tabCount)
{
	return Tab(tabCount) + ";";
}

FString UItemBase::ContainerOpen()
{
	return "[] = " + OpenBrackets();
}

//LineStringCreators
FString UItemBase::LineClassName(FString className)
{
	return OpenBrackets(0) + LineMember(className, true);
}

FString UItemBase::LineMember(FString member, bool useComma)
{
	return Quote() + member + Quote() + Comma(useComma);
}

FString UItemBase::LineMember(int member, bool useComma)
{
	return FString::FromInt(member) + Comma(useComma);
}

FString UItemBase::LineMember(bool member, bool useComma)
{
	return BoolToString(member) + Comma(useComma);
}

FString UItemBase::LineSide(FSide member, bool useComma)
{
	return Side(member) + Comma(useComma);
}

//ClassStringCreators
FString UItemBase::ClassString(FString name, int classTabs)
{
	return Tab(classTabs) + "class " + name + NewLine() + OpenBrackets(classTabs) + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, int member)
{
	return Tab(classMemberTabs) + name + " = " + FString::FromInt(member) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, bool member)
{
	return Tab(classMemberTabs) + name + " = " + BoolToString(member) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, FSide member)
{
	return Tab(classMemberTabs) + name + " = " + Side(member) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, FString member)
{
	return Tab(classMemberTabs) + name + " = " + LineMember(member, false) + SemiColon() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, FVector member)
{
	return Tab(classMemberTabs) + name + ContainerOpen() + member.ToString() + ClosedBrackets() + NewLine();
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, UVirtualItem* member)
{
	return ClassMember("name", classMemberTabs, member ? member->_VariableName.ToString() : "");
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<FVector> vectors)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < vectors.Num(); i++)
	{
		ret += "{" + vectors[i].ToString() + ClosedBrackets() + Comma(i < vectors.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();;
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<int> intArray)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < intArray.Num(); i++)
	{
		ret += FString::FromInt(intArray[i]) + Comma(i < intArray.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<FString> stringArray)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < stringArray.Num(); i++)
	{
		ret += Quote() + stringArray[i] + Quote() + Comma(i < stringArray.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<UVirtualItem*> virtualItem)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < virtualItem.Num(); i++)
	{
		ret += Quote() + virtualItem[i]->_VariableName.ToString() + Quote() + Comma(i < virtualItem.Num());;
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<UClothingItem*> clothingItems)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < clothingItems.Num(); i++)
	{
		ret += clothingItems[i]->MakeString(i < clothingItems.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TMap<UVehicleItem*, FString>  vehicleItems)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	int i = 0;
	for (auto& Elem : vehicleItems)
	{
		i++;
		ret += LineClassName(Elem.Key->_ClassName.ToString());
		ret += LineMember(Elem.Value, false);
		ret += ClosedBrackets() + Comma(i < vehicleItems.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

FString UItemBase::ClassMember(FString name, int classMemberTabs, TArray<UWeaponItem*> weaponItems)
{
	FString ret = Tab(classMemberTabs) + name + ContainerOpen();
	for (int i = 0; i < weaponItems.Num(); i++)
	{
		ret += weaponItems[i]->MakeString(i < weaponItems.Num());
	}
	ret += ClosedBracketSemiColon() + NewLine();
	return ret;
}

