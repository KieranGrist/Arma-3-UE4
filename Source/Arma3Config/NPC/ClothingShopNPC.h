// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNPC.h"
#include "../Shops/ClothingShop.h"

#include "ClothingShopNPC.generated.h"

/**
 *
 */
UCLASS()
class ARMA3CONFIG_API AClothingShopNPC : public ABaseNPC
{
	GENERATED_BODY()
public:
	AClothingShopNPC();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Clothing Shop")
		UClothingShop* _ClothingShop;
};
