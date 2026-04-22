#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "Altar.generated.h"

class USphereComponent;
//DECLARE_MULTICAST_DELEGATE(AltarActivacionTerminada);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAltarActivacionTerminada);

UCLASS()
class CPPCLASETHIRDPERSON_API AAltar : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AAltar();
	
	UPROPERTY(BlueprintAssignable)
	FAltarActivacionTerminada AltarActivacionTerminada;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TiempoEspera = 3.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool isActivado = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMesh> ActiveMesh;
	
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereCollision;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	FTimerHandle TimerEspera;

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact_Implementation(ACharacter* character) override;
	
	UFUNCTION(BlueprintCallable)
	void ActivarCompletado();
};
