// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemBaseDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UItemBaseDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	FText ItemName ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	FText Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	int MaxStack = 99;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	UTexture2D* Sprite;
};
