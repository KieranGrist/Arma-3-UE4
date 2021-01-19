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


FString UShopBase::ClassName()
{
	return UItemBase::Tab() + "class " + _ClassName.ToString() + UItemBase::Tab() + UItemBase::NewLine() + UItemBase::OpenBrakets(1) + UItemBase::NewLine();
}

FString UShopBase::ShopName()
{
	return UItemBase::Quote() + _ShopName.ToString() + UItemBase::Quote();
}

FString UShopBase::Conditions()
{
	return 	UItemBase::Tab() + UItemBase::Tab() + "conditions = " + _Conditions + UItemBase::NewLine();
}

FString UShopBase::Containers()
{
	FString containerText;
	for (auto container : _Containers)
	{
		containerText += container.MakeString();
	}
	return containerText;
}

void UShopBase::UpdateConfigText()
{
	_ConfigText = MakeString();
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

FString UShopBase::MakeString()
{
	FString ret;

	if (bDisplayClassName)
	{
		ret += ClassName();
	}

	if (bDisplplayShopName)
	{
		ret += ShopName();
	}

	if (bDisplaySide)
	{
		ret += Side();
	}

	if (bDisplayConditions)
	{
		ret += Conditions();
	}
	return ret;
}


FString UShopBase::Side()
{
	return UItemBase::Tab() + UItemBase::Tab() + "side = " + _Side + ";" + UItemBase::NewLine();
}


FContainer::FContainer(FName name)
{
	_ContainerName = name;
}

FContainer::FContainer()
{

}

FString FContainer::MakeString()
{
	FString containerString = "";
	for (int i = 0; i < _ContainerItems.Num(); i++)
	{
		containerString += _ContainerItems[i]->MakeString(i == _ContainerItems.Num() - 1);
	}
	return _ContainerName.ToString() + UItemBase::ContainerOpen(2) + containerString + UItemBase::ClosedBraketSemiColon(2);
}

void FContainer::UpdateConfigText()
{
	_ConfigText = MakeString();
}