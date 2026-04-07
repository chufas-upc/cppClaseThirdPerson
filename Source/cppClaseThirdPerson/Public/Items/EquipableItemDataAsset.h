// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBaseDataAsset.h"
#include "EquipableItemDataAsset.generated.h"

/**
 * Un tipo de item que el jugador puede equiparse \n
 * Nota: Es probable que no se utilize, pero de hacerlo, podria tener stats y proveer de efectos \n
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UEquipableItemDataAsset : public UItemBaseDataAsset
{
	GENERATED_BODY()
	
public:
	UEquipableItemDataAsset();
};
