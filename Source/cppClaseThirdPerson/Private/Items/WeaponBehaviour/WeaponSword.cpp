// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/WeaponBehaviour/WeaponSword.h"

void UWeaponSword::WeaponOnStartUse_Implementation(UActorComponent* OwnerComponent)
{
	DefaultShowMessage(FString("Usando arma ola ola"));
	//DefaultShowMessage(OwnerComponent->GetOwner()->GetName());
	
	if (RandoMesh)
	{
		DefaultShowMessage(FString("Setting the mesh up"));
		UStaticMeshComponent* Mesh = OwnerComponent->GetOwner()->GetComponentByClass<UStaticMeshComponent>();
		Mesh->SetStaticMesh(RandoMesh);
	}
	else
	{
		DefaultShowMessage(FString("Im broken!!"));
	}
}

void UWeaponSword::DefaultShowMessage(FString String)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, String);
	}
}
