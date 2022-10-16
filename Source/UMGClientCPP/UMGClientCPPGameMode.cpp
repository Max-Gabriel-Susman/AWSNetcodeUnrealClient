// Copyright Epic Games, Inc. All Rights Reserved.

#include "UMGClientCPPGameMode.h"
#include "UMGClientCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUMGClientCPPGameMode::AUMGClientCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
