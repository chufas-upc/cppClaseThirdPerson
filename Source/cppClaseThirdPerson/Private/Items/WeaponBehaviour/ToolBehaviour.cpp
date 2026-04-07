#include "Items/WeaponBehaviour/ToolBehaviour.h"

void UToolBehaviour::ToolTick_Implementation(UActorComponent* OwnerComponent, float DeltaTime)
{
	UE_LOG(LogHAL, Warning, TEXT("Weapon on Tick not implemented!!"));
}

void UToolBehaviour::ToolOnStartUse_Implementation(UActorComponent* OwnerComponent)
{
	UE_LOG(LogHAL, Warning, TEXT("Weapon on Use not implemented!!"));
}

void UToolBehaviour::ToolOnStopUse_Implementation(UActorComponent* OwnerComponent)
{
	UE_LOG(LogHAL, Warning, TEXT("Weapon on Stop not implemented!!"));
}

UToolBehaviour::UToolBehaviour()
{
}

UToolBehaviour::UToolBehaviour(TObjectPtr<UHandHeldToolDataAsset> ItemDataAsset)
{
	ItemData = ItemDataAsset; 
}

UToolBehaviour* UToolBehaviour::GetCopy(
	UObject* NewOuter,
	UToolBehaviour* Template
)
{
	if (!Template) return nullptr;

	return DuplicateObject<UToolBehaviour>(Template, NewOuter);
}
