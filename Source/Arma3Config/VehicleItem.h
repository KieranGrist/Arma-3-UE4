// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"

#include "VehicleItem.generated.h"

USTRUCT(BlueprintType)
struct FVehicleTexture
{
	GENERATED_BODY()
public:
	FString MakeString(int classMemberTabs, bool useComma);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _TextureName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSide _Side;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> _TexturePaths;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Conditions = "";

};

UCLASS(BlueprintType)
class ARMA3CONFIG_API UVehicleItem : public UItemBase
{
	GENERATED_BODY()
public:
	FString ClassName();

	FString VirtualItemSpace();

	FString Conditions();

	FString Price();

	FString VehicleTextures();

	FString MakeString(bool isEndString);

	//Clothing item class name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName _ClassName;

	//(Display Name, leave as blank for default) 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _VirtualItemSpace;

	//Must Return Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString _Condition;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int _Price;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVehicleTexture> _VehicleTextures;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString _ConfigText = "";

	int _ClassTabs = 1;
	int _ClassMembersTabs = 2;

};
