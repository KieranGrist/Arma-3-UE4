// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"

#include "ClothingShop.generated.h"

class UClothingItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UClothingShop : public UItemBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FName _ShopName;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FString _Conditions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSide _ShopSide = FSide::civ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray < UClothingItem*> _Uniforms;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray < UClothingItem*> _Headgear;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray < UClothingItem*> _Goggles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray < UClothingItem*> _Vests;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray <UClothingItem*> _Backpacks;

	FString  ClassName();
	FString  ShopName();
	FString Conditions();
	FString Side();
	FString Uniforms();
	FString Headgear();
	FString Goggles();
	FString Vests();
	FString Backpacks();

	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;
};
