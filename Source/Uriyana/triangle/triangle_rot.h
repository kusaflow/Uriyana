// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "triangle_rot.generated.h"

UCLASS()
class URIYANA_API Atriangle_rot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atriangle_rot();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = box, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* block;

	bool inX, inY, inZ;
	float speed = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetRotSetUp(bool x, bool y, bool z, float s);
};
