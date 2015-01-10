// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonTutorial.h"
#include "ThirdPersonTutorialGameMode.h"
#include "ThirdPersonTutorialCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TutorialCodeHud.h"

AThirdPersonTutorialGameMode::AThirdPersonTutorialGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//set the default HUD class
	HUDClass = ATutorialCodeHud::StaticClass();

	//base decay rate
	DecayRate = 0.25f;
}

void AThirdPersonTutorialGameMode::Tick(float DeltaSeconds)
{
	AThirdPersonTutorialCharacter* MyCharacter = Cast<AThirdPersonTutorialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	//if the character still has power
	if (MyCharacter->PowerLevel > 0.05)
	{
		//decrease the characters power
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.0f, DeltaSeconds, DecayRate);
	}
	else 
	{
		SetCurrentState(EThirdPersonTutorialPlayerState::EGameOver);
	}

}

void AThirdPersonTutorialGameMode::SetCurrentState(EThirdPersonTutorialPlayerState NewState)
{
	CurrentState = NewState;

	HandleNewState(NewState);
}

void AThirdPersonTutorialGameMode::HandleNewState(EThirdPersonTutorialPlayerState NewState)
{
	switch (NewState)
	{
	//When we're playing, the spawn volumes can spawn
		case EThirdPersonTutorialPlayerState::EPlaying:
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->EnableSpawning();
			}
			break;
	//if the game is over the spawn volumes should deactivate
		case EThirdPersonTutorialPlayerState::EGameOver:
		{
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->DisableSpawning();
			}
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			PlayerController->SetCinematicMode(true, true, true);
		}
			break;

		case EThirdPersonTutorialPlayerState::EUnknown:
		default:
				//Do nothing
			break;
	}
}

void AThirdPersonTutorialGameMode::BeginPlay()
{
	Super::BeginPlay();

	//find all the spawn volume actors
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.Add(SpawnVolumeActor);
		}
	}

	SetCurrentState(EThirdPersonTutorialPlayerState::EPlaying);
}
