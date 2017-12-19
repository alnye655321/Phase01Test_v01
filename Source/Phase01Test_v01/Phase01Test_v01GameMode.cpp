// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Phase01Test_v01GameMode.h"
#include "Phase01Test_v01Character.h"

APhase01Test_v01GameMode::APhase01Test_v01GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = APhase01Test_v01Character::StaticClass();	
}
