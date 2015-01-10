// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdPersonTutorial.h"
#include "Pickup.h"


APickup::APickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsActive = true;

	BaseCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	RootComponent = BaseCollisionComponent;

	//Create the static mesh component
	PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	PickupMesh->SetSimulatePhysics(true);

	//attach the static mesh component to the root component
	PickupMesh->AttachTo(RootComponent);

}


void APickup::OnPickedUp_Implementation()	//<--this is a Blueprint Native event, so we need to add _Implementation
{
	//there is no default behavior for a pickup when its picked up.
}
