// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MultiFirstPerson/MultiFirstPersonCore.h"
#include "GameFramework/PlayerController.h"
#include "MultiFirstPersonPlayerController.generated.h"

class AMultiFirstPersonCharacter;

/**
 * 
 */
UCLASS()
class MULTIFIRSTPERSON_API AMultiFirstPersonPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void SetupInputComponent() override;

private:
	
	void Jump();
	void StopJumping();

	void MoveForward(float fAmount);
	void MoveRight(float fAmount);

	void AddControllerYawInput(float fAmount);
	void TurnAtRate(float fAmount);
	void AddControllerPitchInput(float fAmount);
	void LookUpAtRate(float fAmount);

	AMultiFirstPersonCharacter* GetMultiFirstPersonCharacter();
};
