// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "GarageItem.generated.h"

UCLASS(BlueprintType)
class ARMA3CONFIG_API UGarageItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString ClassName();

	FString Price();

	FString GarageSpawnPosition();

	FString GarageSpawnDirection();

	FString GarageBlacklist();

	FString MakeString(bool isEndString = false);

	//Class name of the garage building
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName;

		//price - Cost of the garage
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	//worldToModel position to spawn vehicles
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector _GarageSpawnPosition;

	//garageSpawnDir - Offset to garage direction to spawn at(+-90 etc).It will be used in the manner : getDir _garage + spawnDir
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _GarageSpawnDirection;

	//garageBlacklists[] - List of blacklisted houses for buying garages
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector>_GarageBlacklists;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
