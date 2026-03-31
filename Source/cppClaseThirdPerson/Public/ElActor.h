// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElActor.generated.h"

UCLASS()
class CPPCLASETHIRDPERSON_API AElActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int salud = 45;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector direcion = FVector();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString nick = "juan";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
