// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Items/ItemBase.h"
#include "Items/VirtualItem.h"
#include "CreateConfig.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ARMA3CONFIG_API UCreateConfig : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(CallInEditor)
		void DataTableToUObjects();

	UFUNCTION(CallInEditor)
		void CrateOrUpdateTableRows();

	UPROPERTY(EditAnywhere)
		UDataTable* _VirtualItems;

	UPROPERTY(EditAnywhere)
		TMap<FString, int> _ItemPrefixes;

	UPROPERTY(EditAnywhere)
		TArray<FName> _ItemNames;

	UPROPERTY(EditAnywhere)
		FString _Path = "/Game/Arma3Config/Items/VirtualItems/";
};
