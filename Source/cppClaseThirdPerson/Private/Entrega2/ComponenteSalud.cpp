#include "Entrega2/ComponenteSalud.h"

UComponenteSalud::UComponenteSalud()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UComponenteSalud::BeginPlay()
{
	Super::BeginPlay();
	SaludCurrent = SaludMax;
}

void UComponenteSalud::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UComponenteSalud::DoDaniar(float cantidad)
{
	SaludCurrent = FMath::Clamp(SaludCurrent - cantidad, 0, SaludMax);
	if (SaludCurrent <= 0)
		HandleMuerte();
	OnActualizarSalud.Broadcast(SaludCurrent);
}

void UComponenteSalud::DoSanar(float cantidad)
{
	SaludCurrent = FMath::Clamp(SaludCurrent + cantidad, 0, SaludMax);
	OnActualizarSalud.Broadcast(SaludCurrent);
}

void UComponenteSalud::HandleMuerte()
{
	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Se ha muerto!"));}
	OnMuerte.Broadcast();
}

