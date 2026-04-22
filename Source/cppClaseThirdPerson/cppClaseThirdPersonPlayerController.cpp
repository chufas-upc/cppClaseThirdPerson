// Copyright Epic Games, Inc. All Rights Reserved.


#include "cppClaseThirdPersonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "cppClaseThirdPerson.h"
#include "Kismet/GameplayStatics.h"
#include "Widget/HUD/CharacterHUD.h"
#include "Widgets/Input/SVirtualJoystick.h"

void AcppClaseThirdPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogcppClaseThirdPerson, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
	
	if (CharacterHUDClass)
	{
		CharacterHUD = CreateWidget<UCharacterHUD>(this, CharacterHUDClass);
		CharacterHUD->AddToPlayerScreen(0);
		UE_LOG(LogTemp, Log, TEXT("Se ha creado el viewport"));
	}
}

void AcppClaseThirdPersonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

void AcppClaseThirdPersonPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TraceLine();
}

void AcppClaseThirdPersonPlayerController::TraceLine()
{
	if (!IsValid(GEngine) || !GEngine->GameViewport)
		return;
	
	//Conseguir tamaño de la pantalla
	FVector2D SizeViewport;
	GEngine->GameViewport->GetViewportSize(SizeViewport);
	
	FVector2D CenterViewport = FVector2D(SizeViewport.X, SizeViewport.Y) * 0.5f;
	
	//Crear linea 
	FVector TraceStart;
	FVector TraceDirection;
	
	UGameplayStatics::DeprojectScreenToWorld(this, CenterViewport, TraceStart, TraceDirection);
	
	//Tracear en el mundo
	FVector TraceEnd = TraceStart + TraceDirection * 400.0f;
	
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, TraceChannel);
	
	//Ola
	CurrentHitActor = HitResult.GetActor();
	if (!CurrentHitActor.IsValid())
		if (IsValid(CharacterHUD))
			CharacterHUD->HideTextInfo();
	
	if (CurrentHitActor == LastHitActor) return;
	
	if (IsValid(CharacterHUD))
		CharacterHUD->ShowItem("ola");
}
