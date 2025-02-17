// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "kusaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class URIYANA_API UkusaGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	float playerXpos = 0;

	UPROPERTY(BlueprintReadOnly)
	float Health = 0;

	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
	bool bGotHit = false;

	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
	float WealponPower = 0;

	UPROPERTY(BlueprintReadWrite, Category = "kusaGun")
	int GunIndex = 0;

	UPROPERTY(BlueprintReadWrite, Category = "kusaGun")
	float CurrentGunStamina = 0;

	UPROPERTY(BlueprintReadWrite, Category = "kusavar")
	int Theme = 0;

	bool ThemeChanged = false;

};
