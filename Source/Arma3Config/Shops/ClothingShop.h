// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShopBase.h"
#include "ClothingShop.generated.h"

class UClothingItem;

USTRUCT(BlueprintType)
struct FClothingShopContainer
{
	GENERATED_BODY()
public:
	FClothingShopContainer();
	FClothingShopContainer(FName name);
	FString MakeString();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Container")
		TArray<UClothingItem*> _ContainerItems;

	void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Container")
		FString _ConfigText = "";
protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Container")
		FName _ContainerName = "Name";
};





UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API UClothingShop : public UShopBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClothingShop();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shop")
		TArray<FClothingShopContainer> _Containers;
};
