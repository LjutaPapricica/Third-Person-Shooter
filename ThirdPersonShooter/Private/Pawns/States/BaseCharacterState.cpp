// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacterState.h"
#include "BaseCharacter.h"
#include "CharacterLocomotionComponent.h"

FBaseCharacterState::FBaseCharacterState(UCharacterLocomotionComponent* LocomotionComponent)
{
	if (LocomotionComponent)
	{
		this->LocomotionComponent = LocomotionComponent;
		this->Character = Cast<ABaseCharacter>(this->LocomotionComponent->GetCharacterOwner());
	}
	else
	{
		this->Character = nullptr;
		this->LocomotionComponent = nullptr;
	}
}

FBaseCharacterState::~FBaseCharacterState()
{
}

void FBaseCharacterState::OnEnter()
{
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *this->ToString());
}

void FBaseCharacterState::OnExit()
{
	this->LocomotionComponent->PreviousState = this->LocomotionComponent->CurrentState;
}

void FBaseCharacterState::Update()
{
	if (Character->IsInCover())
	{
		this->LocomotionComponent->ToCoverState();
	}
}
