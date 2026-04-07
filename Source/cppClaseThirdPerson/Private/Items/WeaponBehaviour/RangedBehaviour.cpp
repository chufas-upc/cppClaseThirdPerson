// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/WeaponBehaviour/RangedBehaviour.h"

void URangedBehaviour::OnShoot()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.0f,
			FColor::Emerald,
			TEXT("Ola soy un arco"));
	}
}