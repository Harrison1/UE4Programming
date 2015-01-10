#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONTUTORIAL_API APickup : public AActor
{
	GENERATED_BODY()

public:

	APickup(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsActive;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* BaseCollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* PickupMesh;

	UFUNCTION(BlueprintNativeEvent)
		void OnPickedUp();
};
