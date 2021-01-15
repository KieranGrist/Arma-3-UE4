// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../BaseObject.h"
#include "ClothingShop.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARMA3CONFIG_API UClothingShop : public UShopBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClothingShop();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	const FString MakeString(const bool isEndString) const override;
		
};
