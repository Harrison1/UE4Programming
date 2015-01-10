// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONTUTORIAL_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:

	ASpawnVolume(const FObjectInitializer& ObjectInitializer);

	//BoxComponent to speicify the spawning area within the level
	UPROPERTY(VisibleInstanceOnly, Category = Spawning)
	class UBoxComponent* WhereToSpawn;

	//The pickup to spawn
	UPROPERTY(EditAnywhere, Category = Spawning)
	TSubclassOf<class APickup> WhatToSpawn;

	//Minimum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
		float SpawnDelayRangeLow;

	//Maximum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
		float SpawnDelayRangeHigh;

	//Finds a random point within the BoxComponent
	UFUNCTION(BlueprintPure, Category = Spawning)
		FVector GetRandomPointInVolume();

	virtual void Tick(float DeltaSeconds) override;

	void EnableSpawning();

	void DisableSpawning();

private:

	//whether or not spawning is enabled
	bool bSpawningEnabled;

	//Calculates a randome spawn delay
	float GetRandomSpawnDelay();

	//The current spawn delay
	float SpawnDelay;

	//Handles the spawning of the new pickup
	void SpawnPickup();

	//Timer for when to spawn the pickup
	float SpawnTime;

};
