#include "Entrega2/Altar.h"

#include "Components/SphereComponent.h"

AAltar::AAltar()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	RootComponent = SphereCollision;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->AttachToComponent(SphereCollision, FAttachmentTransformRules::KeepRelativeTransform);
	
}

void AAltar::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAltar::Interact_Implementation(ACharacter* character)
{
	if (isActivado)
		return;
	
	isActivado = true;
	GetWorldTimerManager().SetTimer(
		TimerEspera,
		this,
		&AAltar::ActivarCompletado,
		TiempoEspera,
		false
	);
	Mesh->SetStaticMesh(ActiveMesh);
}

void AAltar::ActivarCompletado()
{
	AltarActivacionTerminada.Broadcast();
	GetWorldTimerManager().ClearTimer(TimerEspera);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Activación de altar completada"));
	}
}

