// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBehaviour.h"
#include "WeaponSword.generated.h"

/**
 * 
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UWeaponSword : public UWeaponBehaviour
{
	GENERATED_BODY()
	
public:
	virtual void WeaponOnStartUse_Implementation(UActorComponent* OwnerComponent);
	
	UPROPERTY(EditDefaultsOnly);
	UStaticMesh* RandoMesh;
	
private:
	static void DefaultShowMessage(FString String);
};
