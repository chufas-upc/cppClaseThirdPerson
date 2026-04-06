// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeaponBehaviour.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract, EditInlineNew, DefaultToInstanced)
class CPPCLASETHIRDPERSON_API UWeaponBehaviour : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void WeaponTick(UActorComponent* OwnerComponent, float DeltaTime);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void WeaponOnStartUse(UActorComponent* OwnerComponent);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void WeaponOnStopUse(UActorComponent* OwnerComponent);
};
