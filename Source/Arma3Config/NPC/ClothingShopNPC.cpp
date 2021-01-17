// Fill out your copyright notice in the Description page of Project Settings.


#include "ClothingShopNPC.h"

AClothingShopNPC::AClothingShopNPC()
{
	_ClothingShop = CreateDefaultSubobject<UClothingShop>(TEXT("ClothingShop"));
}
