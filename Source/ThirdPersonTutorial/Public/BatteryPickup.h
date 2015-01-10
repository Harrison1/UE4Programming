// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONTUTORIAL_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:

	//Set the amount of power given to player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
		float PowerLevel;

	//this overrides the OnPickedUp function. We use the underscore Implementation because it is a native BlueprintNativeEvent.
	void OnPickedUp_Implementation() override;

	ABatteryPickup(const FObjectInitializer& ObjectInitializer);
};
