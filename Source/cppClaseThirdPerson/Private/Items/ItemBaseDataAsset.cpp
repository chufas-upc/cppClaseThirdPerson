// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemBaseDataAsset.h"

UItemBaseDataAsset::UItemBaseDataAsset()
{
	ItemName = FText::FromString(TEXT("Default Item"));
	Description = FText::FromString(TEXT("This is an Item without an description yet."));
	Category = EItemCategory::Material;
}
