// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBaseDataAsset.h"
#include "ItemVisuals.h"
#include "WeaponBehaviour/ToolBehaviour.h"
#include "HandHeldToolDataAsset.generated.h"

/**
 *	HandHeldToolDataAsset esta pensado para items que se puedan sostener en la mano del jugador.
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UHandHeldToolDataAsset : public UItemBaseDataAsset
{
	GENERATED_BODY()
	
public:
	UHandHeldToolDataAsset();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Tool")
	FItemVisuals HandMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Tool")
	float BaseDamage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Tool")
	FString Anims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Category="Item|Tool")
	TObjectPtr<UToolBehaviour> Behaviour;
};
