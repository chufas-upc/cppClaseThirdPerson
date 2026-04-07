// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ToolBehaviour.generated.h"

class UHandHeldToolDataAsset;
/**
 * 
 */
UCLASS(Blueprintable, Abstract, EditInlineNew, DefaultToInstanced)
class CPPCLASETHIRDPERSON_API UToolBehaviour : public UObject
{
	GENERATED_BODY()
	
public:
	UToolBehaviour();
	UToolBehaviour(TObjectPtr<UHandHeldToolDataAsset> ItemDataAsset);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ToolTick(UActorComponent* OwnerComponent, float DeltaTime);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ToolOnStartUse(UActorComponent* OwnerComponent);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ToolOnStopUse(UActorComponent* OwnerComponent);
	
	// Muy probalbe necesite refactorización
	UFUNCTION(BlueprintPure, BlueprintCallable)
	static UToolBehaviour* GetCopy(UObject* NewOuter, UToolBehaviour* Template);
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UHandHeldToolDataAsset> ItemData; 
};
