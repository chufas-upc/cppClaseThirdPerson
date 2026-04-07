// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemCategory.h"
#include "Engine/DataAsset.h"
#include "ItemBaseDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UItemBaseDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UItemBaseDataAsset();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	FText ItemName ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	EItemCategory Category;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	FText Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	int MaxStack = 99;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	TObjectPtr<UTexture2D> Sprite;
};
