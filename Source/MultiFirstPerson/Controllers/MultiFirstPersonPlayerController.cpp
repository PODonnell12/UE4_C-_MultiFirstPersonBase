// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiFirstPersonPlayerController.h"

#include "GameFramework/Pawn.h"
#include "MultiFirstPerson/MultiFirstPersonCharacter.h"

void AMultiFirstPersonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMultiFirstPersonPlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMultiFirstPersonPlayerController::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &AMultiFirstPersonPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMultiFirstPersonPlayerController::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &AMultiFirstPersonPlayerController::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AMultiFirstPersonPlayerController::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &AMultiFirstPersonPlayerController::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AMultiFirstPersonPlayerController::LookUpAtRate);

#if ENABLE_TOUCH_DEVICES
	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &AMultiFirstPersonPlayerController::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AMultiFirstPersonPlayerController::TouchStopped);
#endif

#if ENABLE_VR
	// VR headset functionality
	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AMultiFirstPersonPlayerController::OnResetVR);
#endif
}

AMultiFirstPersonCharacter* AMultiFirstPersonPlayerController::GetMultiFirstPersonCharacter()
{
	if (APawn* pPawn = GetPawn())
	{
		if (AMultiFirstPersonCharacter* pCharacter = static_cast<AMultiFirstPersonCharacter*>(pPawn))
		{
			return pCharacter;
		}
	}

	return nullptr;
}

void AMultiFirstPersonPlayerController::Jump()
{
	if (AMultiFirstPersonCharacter* pCharacter = GetMultiFirstPersonCharacter())
	{
		pCharacter->Jump();
	}
}

void AMultiFirstPersonPlayerController::StopJumping()
{
	if (AMultiFirstPersonCharacter* pCharacter = GetMultiFirstPersonCharacter())
	{
		pCharacter->StopJumping();
	}
}

void AMultiFirstPersonPlayerController::MoveForward(float fAmount)
{
	if (AMultiFirstPersonCharacter* pCharacter = GetMultiFirstPersonCharacter())
	{
		pCharacter->MoveForward(fAmount);
	}
}

void AMultiFirstPersonPlayerController::MoveRight(float fAmount)
{
	if (AMultiFirstPersonCharacter* pCharacter = GetMultiFirstPersonCharacter())
	{
		pCharacter->MoveRight(fAmount);
	}
}

void AMultiFirstPersonPlayerController::TurnAtRate(float fAmount)
{
	if (AMultiFirstPersonCharacter* pCharacter = GetMultiFirstPersonCharacter())
	{
		pCharacter->TurnAtRate(fAmount);
	}
}

void AMultiFirstPersonPlayerController::AddControllerYawInput(float fAmount)
{
	if (APawn* pPawn = GetPawn())
	{
		pPawn->AddControllerYawInput(fAmount);
	}
}

void AMultiFirstPersonPlayerController::AddControllerPitchInput(float fAmount)
{
	if (APawn* pPawn = GetPawn())
	{
		pPawn->AddControllerPitchInput(fAmount);
	}
}

void AMultiFirstPersonPlayerController::LookUpAtRate(float fAmount)
{
	if (AMultiFirstPersonCharacter* pCharacter = GetMultiFirstPersonCharacter())
	{
		pCharacter->LookUpAtRate(fAmount);
	}
}