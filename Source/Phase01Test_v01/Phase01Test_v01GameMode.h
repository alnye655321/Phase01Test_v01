// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Phase01Test_v01GameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of Phase01Test_v01Character
 */
UCLASS(minimalapi)
class APhase01Test_v01GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	APhase01Test_v01GameMode();
};
