// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "LicenseItem.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class ARMA3CONFIG_API ULicenseItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString MakeString();
	FString ClassName();
	FString VariableName();
	FString DisplayName();
	FString Price();
	FString LicenseIllegal();
	FString LicenseSide();

	//variable = Variable Name This is also the class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _VariableName;
	//displayName = Item Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _DisplayName;
	//buyPrice = Item Buy Price
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;
	//illegal = Illegal Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _LicenseIllegal = false;
	//Side of the License
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSide _LicenseSide = FSide::civ;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;
};
