#pragma once
 
#include "CoreMinimal.h"
#include "ItemCategory.generated.h"
 
/**
 * Custom enum to demonstrate how to expose enums to Blueprints.
 */
UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Material,
	Weapon,
	Tool,
	Armor,
	Artifact,
	Consumable,
	Mission
};