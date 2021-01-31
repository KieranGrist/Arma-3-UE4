// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"

#include "SpawnItem.generated.h"

class UVirtualItem;

UCLASS(hidecategories = Object, BlueprintType)
class ARMA3CONFIG_API USpawnItem : public UItemBase
{
	GENERATED_BODY()

public:
	FString ClassName();
	FString DisplayName();
	FString SpawnMarker();
	FString Icon();
	FString Conditions();
	FString MakeString();

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _ClassName;
	//Whats displayed to the players
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _DisplayName;
		//Name Of Marker
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _SpawnMarker;
	//Icon Displayed
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Icon;
		//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 2;
	int _ClassMembersTabs = 3;
};
