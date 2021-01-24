// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"


#include "HouseItem.generated.h"

UCLASS(BlueprintType)
class ARMA3CONFIG_API UHouseItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString ClassName();

	FString Price();

	FString NumberOfCrates();

	FString RestrictedPositions();

	FString CanGarage();

	FString GarageSpawnPosition();

	FString GarageSpawnDirection();

	FString GarageBlacklist();

	FString LightPosition();

	FString MakeString();

	//Class name of the garage building
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName;

	//price - Cost of the building
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//numberCrates - Allowed number of crates
	int _NumberOfCrates;

		//restrictedPos[] - Same as the old fn_getBuildingPositions.A list of restricted building positions(i.e, to stop spawning outside, or by windows etc)	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int> _RestrictedPositions;

	//canGarage - True if the building can be used as a garage(need to buy ontop)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool _CanGarage = false;

	//worldToModel position to spawn vehicles
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector _GarageSpawnPosition;

	//garageSpawnDir - Offset to garage direction to spawn at(+-90 etc).It will be used in the manner : getDir _garage + spawnDir
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _GarageSpawnDirection;

	//garageBlacklists[] - List of blacklisted houses for buying garages
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector>_GarageBlacklist;
	//WorldToModel position for the light
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector _LightPosition;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
