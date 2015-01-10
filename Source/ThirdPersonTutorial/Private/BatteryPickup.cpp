// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdPersonTutorial.h"
#include "BatteryPickup.h"


ABatteryPickup::ABatteryPickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//base level of the battery
	PowerLevel = 150.0f;
}

void ABatteryPickup::OnPickedUp_Implementation()
{
	//call the parent implementation of OnPickedUp first
	Super::OnPickedUp_Implementation();

	//Destroy the battery
	Destroy();
}