// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "ItemBase.generated.h"

class UVirtualItem;
class UVehicleItem;
class UClothingItem;
class UWeaponItem;

UENUM(BlueprintType)
enum class FSide : uint8
{
	civ,
	cop,
	med
};

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UItemBase : public UDataAsset
{
	GENERATED_BODY()

public:
	static FString MapName();

	static  FString Quote();
	static FString NewLine();
	static FString Comma(bool useComma);
	static  FString Tab(int tabCount);
	static FString Side(FSide side);
	static	FString BoolToString(bool inBool);
	static FString OpenBrackets(int tabCount = 0);
	static FString ClosedBracketsComma(int tabCount = 0);
	static FString ClosedBrackets(int tabCount = 0);
	static FString ClosedBracketSemiColon(int tabCount = 0);
	static FString SemiColon(int tabCount = 0);
	static FString ContainerOpen();

	//LineStringCreators
	static FString LineClassName(FString className);
	static FString LineMember(FString member, bool useComma);
	static FString LineMember(int member, bool useComma);
	static FString LineMember(bool member, bool useComma);
	static FString LineSide(FSide member, bool useComma);

	//ClassStringCreators
	static FString ClassString(FString name, int classTabs);
	static FString ClassMember(FString name, int classMemberTabs, int member);
	static FString ClassMember(FString name, int classMemberTabs, bool member);
	static FString ClassMember(FString name, int classMemberTabs, FSide member);
	static FString ClassMember(FString name, int classMemberTabs, FString member);
	static FString ClassMember(FString name, int classMemberTabs, FVector member);
	static FString ClassMember(FString name, int classMemberTabs, UVirtualItem* member);
	static FString ClassMember(FString name, int classMemberTabs, TArray<FVector> vectors);
	static FString ClassMember(FString name, int classMemberTabs, TArray<int> intArray);
	static FString ClassMember(FString name, int classMemberTabs, TArray<FString> stringArray);
	static FString ClassMember(FString name, int classMemberTabs, TArray<UVirtualItem*> virtualItem);
	static FString ClassMember(FString name, int classMemberTabs, TArray<UClothingItem*> clothingItems);
	static FString ClassMember(FString name, int classMemberTabs, TMap<UVehicleItem*, FString>  vehicleItems);
	static FString ClassMember(FString name, int classMemberTabs, TArray<UWeaponItem*> weaponItems);

	UPROPERTY(EditAnywhere, Category = "Buxton Only")
		int _ClassTabs = 2;
	UPROPERTY(EditAnywhere, Category = "Buxton Only")
		int _ClassMembersTabs = 3;
};
