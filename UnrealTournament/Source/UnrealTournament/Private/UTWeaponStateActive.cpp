// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UnrealTournament.h"
#include "UTWeaponState.h"
#include "UTWeaponStateActive.h"
#include "UTWeaponStateFiring.h"

void UUTWeaponStateActive::BeginState(const UUTWeaponState* PrevState)
{
	// see if we need to process a pending putdown
	if (GetOuterAUTWeapon()->GetUTOwner()->GetPendingWeapon() == NULL || !GetOuterAUTWeapon()->PutDown())
	{
		// check for any firemode already pending
		for (uint8 i = 0; i < GetOuterAUTWeapon()->GetNumFireModes(); i++)
		{
			if (GetOuterAUTWeapon()->GetUTOwner()->IsPendingFire(i))
			{
				GetOuterAUTWeapon()->CurrentFireMode = i;
				GetOuterAUTWeapon()->GotoState(GetOuterAUTWeapon()->FiringState[i]);
				return;
			}
		}
	}
}

void UUTWeaponStateActive::BeginFiringSequence(uint8 FireModeNum)
{
	if (GetOuterAUTWeapon()->FiringState.IsValidIndex(FireModeNum))
	{
		GetOuterAUTWeapon()->CurrentFireMode = FireModeNum;
		GetOuterAUTWeapon()->GotoState(GetOuterAUTWeapon()->FiringState[FireModeNum]);
	}
}