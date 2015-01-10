// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "TutorialCodeHud.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONTUTORIAL_API ATutorialCodeHud : public AHUD
{
	GENERATED_BODY()

public:
	
	ATutorialCodeHud(const FObjectInitializer& ObjectInitializer);

	//Variable for storing the font
	UPROPERTY()
	UFont* HUDFont;

	//Pirmary draw call for the HUD
	virtual void DrawHUD() override;
	
};
