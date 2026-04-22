#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};
class CPPCLASETHIRDPERSON_API IInteractable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent)
	void Interact(ACharacter* player);
};
