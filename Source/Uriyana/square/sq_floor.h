// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "sq_floor.generated.h"

UCLASS()
class URIYANA_API Asq_floor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Asq_floor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* block;


	float znum;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void set_znum(int z);

};
