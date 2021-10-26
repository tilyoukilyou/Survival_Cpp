// Copyright Epic Games, Inc. All Rights Reserved.

#include "Survival_CppGameMode.h"
#include "Survival_CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASurvival_CppGameMode::ASurvival_CppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
