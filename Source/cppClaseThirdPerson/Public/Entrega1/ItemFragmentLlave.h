#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Entrega1/ItemBase.h"
#include "ItemFragmentLlave.generated.h"

UCLASS()
class CPPCLASETHIRDPERSON_API AItemFragmentLlave : public AItemBase
{
	GENERATED_BODY()
	
public:
	AItemFragmentLlave();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
