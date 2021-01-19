// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Items/ItemBase.h"


#include "ShopBase.generated.h"


//class AItemBase;
USTRUCT(BlueprintType)
struct FContainer 
{
	GENERATED_BODY()
	public:
		FContainer();
	FContainer(FName name);
	FString MakeString();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Container")
		TArray<UItemBase*> _ContainerItems;

		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Container")
		FString _ConfigText = "";
protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Container")
	FName _ContainerName = "Name";
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARMA3CONFIG_API UShopBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShopBase();

	FString ClassName();

	FString ShopName();

	FString Side();

	FString Conditions();

	FString Containers();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shop", meta = (EditCondition = "bDisplayClassName"))
		FName _ClassName = "Class Name";
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shop", meta = (EditCondition = "bDisplplayShopName"))
		FName _ShopName = "Shop Name";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shop", meta = (EditCondition = "bDisplaySide"))
		FString	_Side = "civ";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shop", meta = (EditCondition = "bDisplayConditions"))
		FString _Conditions = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shop")
	TArray<FContainer> _Containers;

	UFUNCTION(CallInEditor)
		void UpdateConfigText();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Shop", meta = (EditCondition = "bDisplayClassName"))
		FString _ConfigText = "";

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayClassName = false;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplplayShopName = false;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplaySide = false;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bDisplayConditions = false;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FString MakeString();
};
