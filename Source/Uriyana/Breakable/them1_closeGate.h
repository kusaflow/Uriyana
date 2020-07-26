// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "them1_closeGate.generated.h"

UCLASS()
class URIYANA_API Athem1_closeGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Athem1_closeGate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
