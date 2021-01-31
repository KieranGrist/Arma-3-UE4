// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"

#include "ProcessItem.generated.h"

class UVirtualItem;

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UProcessItem : public UItemBase
{

	GENERATED_BODY()

public:
	FString ClassName();
	FString MaterialsRequired();
	FString MaterialsGiven();
	FString ProgressBarText();
	FString NoLicenseCost();
	FString MakeString();

	static FString VirtualPairToString(TPair<UVirtualItem*, int> pair, bool useComma);
	static FString VirtualMapToString(FString name, int classMemberTabs, TMap<UVirtualItem*, int> virtualItemMap);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString _ClassName;

	//Resource gathered in the zone 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<UVirtualItem*, int> _MaterialsRequired;

	//MaterialsGive (Returned items) = Array - Format -> {{"ITEM CLASS",HOWMANY}}
	TPair<UVirtualItem*, int> _MaterialsGiven;


	//Text(Progress Bar Text)
	FString _ProgressBarText;
	// NoLicenseCost (Cost to process w/o license)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _NoLicenseCost = 30;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;
};
