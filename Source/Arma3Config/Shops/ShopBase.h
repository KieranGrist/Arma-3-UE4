// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Items/Public/ItemBase.h"


#include "ShopBase.generated.h"

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UShopBase : public UItemBase
{
	GENERATED_BODY()

public:	
	FString ClassName();

	FString ShopName();

	FString Side();

	FString Conditions();

	FString Containers();

	FString MakeString();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FName _ClassName = "Class Name";
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FName _ShopName = "Shop Name";

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString	_Side = "civ";

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _Conditions = "";

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
