// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdPersonTutorial.h"
#include "TutorialCodeHud.h"
#include "ThirdPersonTutorialGameMode.h"
#include "ThirdPersonTutorialCharacter.h"
#include "Kismet/GameplayStatics.h "
#include "Engine/Canvas.h"
#include "Engine/Font.h"

ATutorialCodeHud::ATutorialCodeHud(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//Use the RobotoDistanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void ATutorialCodeHud::DrawHUD()
{
	//Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	//Call to the parent versions of DrawHUD
	//Change Super::DrawHUD to the below;
	&AHUD::DrawHUD;

	//Get the character and print its power level
	AThirdPersonTutorialCharacter* MyCharacter = Cast<AThirdPersonTutorialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	FString PowerLevelString = FString::Printf(TEXT("%10.1f"), FMath::Abs(MyCharacter->PowerLevel));
	DrawText(PowerLevelString, FColor::White, 50, 50, HUDFont);

	AThirdPersonTutorialGameMode* MyGameMode = Cast<AThirdPersonTutorialGameMode>(UGameplayStatics::GetGameMode(this));

	//if the game is over
	if (MyGameMode->GetCurrentState() == EThirdPersonTutorialPlayerState::EGameOver)
	{
		//create a variable for storing the size of printing Game Over
		FVector2D GameOverSize;
		GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
		DrawText(TEXT("GAME OVER"), FColor::White, (ScreenDimensions.X - GameOverSize.X) / 2.0f, (ScreenDimensions.Y - GameOverSize.Y) / 2.0f, HUDFont);

	}
}


