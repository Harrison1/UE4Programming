// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SpawnVolume.h"
#include "ThirdPersonTutorialGameMode.generated.h"


//enum to store the current state of gameplay
enum class EThirdPersonTutorialPlayerState : uint8 //** you can replace short with uint8 */
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AThirdPersonTutorialGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AThirdPersonTutorialGameMode(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power)
	float DecayRate;

	EThirdPersonTutorialPlayerState GetCurrentState() const;

	void SetCurrentState(EThirdPersonTutorialPlayerState NewState);

	virtual void BeginPlay() override;

private:

	TArray<ASpawnVolume*> SpawnVolumeActors;

	EThirdPersonTutorialPlayerState CurrentState;

	void HandleNewState(EThirdPersonTutorialPlayerState NewState);
};

FORCEINLINE EThirdPersonTutorialPlayerState AThirdPersonTutorialGameMode::GetCurrentState() const
{
	return CurrentState;
}





