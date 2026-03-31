// Fill out your copyright notice in the Description page of Project Settings.


#include "ElActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "steam/steam_api.h"

APawn* Player;

// Sets default values
AElActor::AElActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AElActor::BeginPlay()
{
	Super::BeginPlay();
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	//Testing steam
	//FString nick = Identity->GetPlayerNickname(0);
}

// Called every frame
void AElActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(direcion * DeltaTime));
	
	FRotator lookAt = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Player->GetActorLocation());
	SetActorRotation(lookAt);
}

