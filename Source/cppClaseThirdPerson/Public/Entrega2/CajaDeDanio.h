#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CajaDeDanio.generated.h"

class UBoxComponent;
class UComponenteSalud;

UCLASS()
class CPPCLASETHIRDPERSON_API ACajaDeDanio : public AActor
{
	GENERATED_BODY()

public:
	ACajaDeDanio();
	
	UPROPERTY(EditAnywhere)
	float SegundosDanio = 0.5f;
	UPROPERTY(EditAnywhere)
	float DaniooPorTick = 10.0f;

private:
	UPROPERTY()
	FTimerHandle TimerHandle;
	UPROPERTY()
	TObjectPtr<UComponenteSalud> PlayerSaludComponente;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> Collision;

protected:
	virtual void BeginPlay() override;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION()
	void DanioTick();
};
