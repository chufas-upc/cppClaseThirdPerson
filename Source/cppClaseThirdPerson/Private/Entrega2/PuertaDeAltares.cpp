// Fill out your copyright notice in the Description page of Project Settings.


#include "Entrega2/PuertaDeAltares.h"

#include "Entrega2/Altar.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APuertaDeAltares::APuertaDeAltares()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APuertaDeAltares::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Altars;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAltar::StaticClass(), Altars);

	for (auto Altar : Altars)
	{
		AAltar* AltarCast = Cast<AAltar>(Altar);
		AltaresRestantes++;
		AltarCast->AltarActivacionTerminada.AddDynamic(this,&APuertaDeAltares::DescontarAltar);
	}
}

// Called every frame
void APuertaDeAltares::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APuertaDeAltares::DescontarAltar()
{
	AltaresRestantes--;
	if (AltaresRestantes == 0)
		AbrirPuerta();
}

void APuertaDeAltares::AbrirPuerta_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("La puerta se ha abierto"));
	Destroy();
}

