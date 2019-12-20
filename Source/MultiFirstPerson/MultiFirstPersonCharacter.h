// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MultiFirstPersonCore.h"
#include "GameFramework/Character.h"
#include "MultiFirstPersonCharacter.generated.h"

class UAnimBlueprint;
class USkeletalMesh;

UCLASS(config=Game)
class AMultiFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	AMultiFirstPersonCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
	USkeletalMesh* FPMeshAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
	USkeletalMesh* TPMeshAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
	UAnimBlueprint* FPAnimBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
	UAnimBlueprint* TPAnimBP;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void ToggleFirstThirdPerson();

private:

	virtual void BeginPlay() override;

protected:

#if ENABLE_VR
	/** Resets HMD orientation in VR. */
	void OnResetVR();
#endif

#if ENABLE_TOUCH_DEVICES
	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
#endif

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

