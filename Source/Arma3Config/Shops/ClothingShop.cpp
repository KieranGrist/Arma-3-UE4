// Fill out your copyright notice in the Description page of Project Settings.
#include "ClothingShop.h"



// Sets default values for this component's properties
UClothingShop::UClothingShop()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	_ShopName = "ClothingShop";
	_Containers.Emplace(FContainer("uniforms"));
	_Containers.Emplace(FContainer("headgear"));
	_Containers.Emplace(FContainer("goggles"));
	_Containers.Emplace(FContainer("vests"));
	_Containers.Emplace(FContainer("backpacks"));

	 bDisplplayShopName = true;
	 bDisplaySide = true;
	 bDisplayConditions = true;
}

void UClothingShop::BeginPlay()
{

}

void UClothingShop::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}
