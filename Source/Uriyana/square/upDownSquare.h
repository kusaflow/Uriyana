// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "upDownSquare.generated.h"

UCLASS()
class URIYANA_API AupDownSquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AupDownSquare();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* block;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "kusaVar")
	float downLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "kusaVar")
	float upLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "kusaVar")
	float speed;

	bool bMovingUp = true;





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
