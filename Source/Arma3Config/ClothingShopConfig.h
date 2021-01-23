// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Shops/ClothingShop.h"
#include "Items/Public/ItemBase.h"
#include "ClothingShopConfig.generated.h"

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UClothingShopConfig : public UItemBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName _ClassName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UClothingShop*> _ClothingShops;

	FString MakeString(bool isEndString = false);
};
