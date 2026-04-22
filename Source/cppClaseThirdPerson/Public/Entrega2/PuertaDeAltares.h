// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuertaDeAltares.generated.h"

UCLASS()
class CPPCLASETHIRDPERSON_API APuertaDeAltares : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuertaDeAltares();
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	int32 AltaresRestantes = 0;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void AbrirPuerta();
	UFUNCTION()
	void DescontarAltar();
};
