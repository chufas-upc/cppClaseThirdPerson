// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ToolBehaviour.h"
#include "RangedBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class CPPCLASETHIRDPERSON_API URangedBehaviour : public UToolBehaviour
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void OnShoot();
};
