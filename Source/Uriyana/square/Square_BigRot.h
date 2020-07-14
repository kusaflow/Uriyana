// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Square_BigRot.generated.h"

UCLASS()
class URIYANA_API ASquare_BigRot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASquare_BigRot();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = box, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* block1;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* block2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* block3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* block4;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
