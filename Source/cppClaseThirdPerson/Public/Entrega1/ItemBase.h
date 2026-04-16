#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Entrega2/Interactable.h"
#include "ItemBase.generated.h"

UCLASS()
class CPPCLASETHIRDPERSON_API AItemBase : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AItemBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USphereComponent> SphereCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Mesh;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
