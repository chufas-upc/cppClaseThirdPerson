// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterHUD.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class CPPCLASETHIRDPERSON_API UCharacterHUD : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TextInfo;
	
public:
	void HideTextInfo();
	void ShowItem(const char* Str);
};
