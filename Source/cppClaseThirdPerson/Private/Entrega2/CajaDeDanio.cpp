#include "Entrega2/CajaDeDanio.h"

#include "Components/BoxComponent.h"
#include "Entrega2/ComponenteSalud.h"

ACajaDeDanio::ACajaDeDanio()
{
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = Collision;
}

// Called when the game starts or when spawned
void ACajaDeDanio::BeginPlay()
{
	Super::BeginPlay();
}

void ACajaDeDanio::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (!IsValid(OtherActor))
		return;
	
	PlayerSaludComponente = OtherActor->FindComponentByClass<UComponenteSalud>();
	if (!PlayerSaludComponente)
		return;
	
	GetWorldTimerManager().SetTimer(
		TimerHandle,
		this,
		&ACajaDeDanio::DanioTick,
		SegundosDanio,
		true);
}

void ACajaDeDanio::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	//Verificar si Other actor es el player
	GetWorldTimerManager().ClearTimer(TimerHandle);
}

void ACajaDeDanio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACajaDeDanio::DanioTick()
{
	PlayerSaludComponente->DoDaniar(DaniooPorTick);
}

