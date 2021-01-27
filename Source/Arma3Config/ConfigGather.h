// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "ConfigGather.generated.h"

class UResourceItem;
class UMineralItem;

UCLASS(BlueprintType)
class ARMA3CONFIG_API UConfigGather : public UItemBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray <UResourceItem*> _Resources;
		TArray <UMineralItem*> _Minerals;

	FString MakeString();

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 0;
	int _ClassMembersTabs = 1;
};
