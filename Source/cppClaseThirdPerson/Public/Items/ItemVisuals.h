#pragma once

#include "CoreMinimal.h"
#include "ItemVisuals.generated.h"

USTRUCT(BlueprintType)
struct FItemVisuals
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item/Visuals")
	UStaticMesh* Mesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item/Visuals")
	UMaterial* Material;
};
