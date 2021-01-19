// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "VirtualItemBase.generated.h"

/**
 *
 */
UCLASS(hidecategories = "StaticMesh", BlueprintType)
class ARMA3CONFIG_API UVirtualItemBase : public UItemBase
{
	GENERATED_BODY()
public:
	 FString MakeString(bool isEndString)  override;
	FString Weight();
	FString Illegal();
	FString Edible();
	FString Drinkable();
	FString Icon();

	//Item Weight
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayWeight"), Category = "Virtual Item Base")
		int _Weight = -1;

	// illegal = Illegal Item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayIllegal"), Category = "Virtual Item Base")
		bool _Illegal = false;

	//Item Edible(-1 = Disabled, other values = added value)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayEdible"), Category = "Virtual Item Base")
		int _Edible = -1;

	// Drinkable(-1 = Disabled, other values = added value)``
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayDrinkable"), Category = "Virtual Item Base")
		int _Drinkable = -1;

	//Icon Of the item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDisplayIcon"), Category = "Virtual Item Base")
		FString _Icon = "Item Icon";

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayWeight = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayIllegal = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayEdible = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayDrinkable = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayIcon = false;

};
