// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Items/Public/ItemBase.h"

#include "ClothingShop.generated.h"

class UClothingItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UClothingShop : public UItemBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClothingShop();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FName _ShopName;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FString _Conditions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSide _ShopSide = FSide::civ;

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClothingItem* _Uniforms;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClothingItem* _Headgear;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClothingItem* _Goggles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClothingItem* _Vests;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClothingItem* _Backpacks;

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
};
