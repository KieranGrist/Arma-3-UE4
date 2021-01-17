// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopBase.h"

// Sets default values for this component's properties
UShopBase::UShopBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	TArray<FContainer> _Containers;

}


// Called when the game starts
void UShopBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UShopBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

