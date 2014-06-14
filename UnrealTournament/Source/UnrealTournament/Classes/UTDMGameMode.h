// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "UTDMGameMode.generated.h"

UCLASS(minimalapi)
class AUTDMGameMode : public AUTGameMode
{
	GENERATED_UCLASS_BODY()

	/** If TRUE then noone has been killed yet */
	UPROPERTY()
	uint32 bFirstBlood:1;

	/** Flag whether "X kills remain" has been played yet */
	UPROPERTY()
	uint32 bPlayedTenKillsRemain:1;

	UPROPERTY()
	uint32 bPlayedFiveKillsRemain:1;

	UPROPERTY()
	uint32 bPlayedOneKillRemains:1;
};



