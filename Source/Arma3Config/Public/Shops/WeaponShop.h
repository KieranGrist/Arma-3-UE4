// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreateConfig.h"

#include "WeaponShop.generated.h"

UCLASS(BlueprintType)
class ARMA3CONFIG_API UWeaponShop : public UItemBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FName _ShopName;
		
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ESide _ShopSide = ESide::civ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FString _Conditions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UItemBase*> _Weapons;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UItemBase*> _Magazines;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UItemBase*> _Accessories;

	FString ClassName();
	FString ShopName();
	FString Conditions();
	FString Side();
	FString Weapons();
	FString Magazines();
	FString Accessories();
	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";


	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;

};
