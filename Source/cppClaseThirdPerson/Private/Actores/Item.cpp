#include "Actores/Item.h"

#include "cppClaseThirdPersonCharacter.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;
	
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EsferaMesh"));
	SphereMesh->SetupAttachment(RootComponent);
	
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->SetupAttachment(SphereMesh);
	
	
}
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	AcppClaseThirdPersonCharacter* MiCharacter = Cast<AcppClaseThirdPersonCharacter>(OtherActor);
	
	if (MiCharacter)
	{
		MiCharacter->MostrarMensaje();
	}
}

