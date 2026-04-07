// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ToolBehaviour.h"
#include "MeleeComboBehaviour.generated.h"

/**
 *	TODO: Agregar EventDispatchers o algun sistema para que el behaviour reaccione a el gampelay
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UMeleeComboBehaviour : public UToolBehaviour
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly);
	TObjectPtr<UStaticMesh> RandoMesh;
	
	UPROPERTY(EditDefaultsOnly);
	int8 MaxComboCounter;
	
private:
	void ToolOnStartUse_Implementation(UActorComponent* OwnerComponent) override;
	static void DefaultShowMessage(FString String);
	
	UPROPERTY();
	int8 Combo = 0;
};
