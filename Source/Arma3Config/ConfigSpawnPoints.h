// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "ConfigSpawnPoints.generated.h"

class USpawnItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UConfigSpawnPoints : public UItemBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray <USpawnItem*> _CivlianSpawns;
		TArray <USpawnItem*> _CopSpawns;
		TArray <USpawnItem*> _MedicSpawns;

	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";
};
