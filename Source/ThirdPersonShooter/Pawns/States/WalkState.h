// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include "ThirdPersonShooter/Pawns/States/BaseCharacterState.h"

class THIRDPERSONSHOOTER_API FWalkState : public FBaseCharacterState
{
public:

	FWalkState();

	FWalkState(UCharacterLocomotionComponent* LocomotionComponent);

	virtual void OnEnter() override;

	virtual void Update() override;

	virtual FString ToString() const override;
};
