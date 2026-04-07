// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/WeaponBehaviour/MeleeComboBehaviour.h"

void UMeleeComboBehaviour::ToolOnStartUse_Implementation(UActorComponent* OwnerComponent)
{
    Super::ToolOnStartUse_Implementation(OwnerComponent);
    UE_LOG(LogTemp, Log, TEXT("Executing combo attack #%d"), Combo);
	
	OwnerComponent->GetOwner()->AddActorWorldOffset(FVector(100.0f, 0.0f, 0.0f));
	
	Combo++;
	if (Combo >= MaxComboCounter)
	{
		Combo = 0;
		OwnerComponent->GetOwner()->AddActorWorldOffset(FVector(0.0f, 100.0f, 0.0f));
		UE_LOG(LogTemp, Log, TEXT("Last combo attack executed!!"));
	}
}

void UMeleeComboBehaviour::DefaultShowMessage(FString String)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, String);
	}
}