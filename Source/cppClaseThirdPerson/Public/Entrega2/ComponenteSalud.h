#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponenteSalud.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMuerte);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActualizarSalud, float, health);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CPPCLASETHIRDPERSON_API UComponenteSalud : public UActorComponent
{
	GENERATED_BODY()

public:
	UComponenteSalud();
	
	UPROPERTY(BlueprintReadWrite)
	FOnMuerte OnMuerte;
	
	UPROPERTY(BlueprintReadWrite)
	FOnActualizarSalud OnActualizarSalud;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SaludMax = 100;
	
private:
	UPROPERTY()
	float SaludCurrent;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void DoDaniar(float cantidad);
	
	UFUNCTION(BlueprintCallable)
	void DoSanar(float cantidad);
	
private:
	UFUNCTION()
	void HandleMuerte();
};
