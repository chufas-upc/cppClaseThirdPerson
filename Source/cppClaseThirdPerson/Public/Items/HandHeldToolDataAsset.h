// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBaseDataAsset.h"
#include "ItemVisuals.h"
#include "WeaponBehaviour/WeaponBehaviour.h"
#include "HandHeldToolDataAsset.generated.h"

/**
 *	ola
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UHandHeldToolDataAsset : public UItemBaseDataAsset
{
	GENERATED_BODY()
	
public:
	UHandHeldToolDataAsset();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item/HandHeld")
	FItemVisuals HandMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Category="Item/HandHeld")
	UWeaponBehaviour* Behaviour;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item/HandHeld")
	float Damage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item/HandHeld")
	FString Anims;
};
