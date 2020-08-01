// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "mainChar.generated.h"

UCLASS()
class URIYANA_API AmainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AmainChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, category = "G1_BALLS")
	TSubclassOf<class AThrowBall> G1_ball1;

	UPROPERTY(EditDefaultsOnly, category = "G1_BALLS")
	TSubclassOf<class AThrowBall> G1_ball2;

	UPROPERTY(EditDefaultsOnly, category = "G1_BALLS")
	TSubclassOf<class AThrowBall> G1_ball3;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "gunRelease", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* fireLoc;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "gun", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* gun;

	UPROPERTY(EditDefaultsOnly, category = "sound")
	class USoundCue* Gun_1_Launch;

	UPROPERTY(EditDefaultsOnly, category = "sound")
	class USoundCue* Gun_1_Launch_sifi;


	//animations
	UPROPERTY(EditDefaultsOnly, category = "Animation")
	class UAnimationAsset* gun1Anim;


	
	int GunIndex;
	float CurrentGunStamina;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForword();

	void shoot();

	UFUNCTION()
	void CameraYaw_z(float val);

	UFUNCTION()
	void CameraPitch_y(float val);

};
