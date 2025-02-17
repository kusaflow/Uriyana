// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Glass_001.generated.h"

UCLASS()
class URIYANA_API AGlass_001 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlass_001();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* block;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDestructibleComponent* destr;

	bool inRight = true;
	bool broken = false;

	UPROPERTY(EditAnywhere, Category = "damage")
		float basedamage = 0;

	UPROPERTY(EditAnywhere, Category = "damage")
		float impulseRadius = 0;

	UPROPERTY(EditAnywhere, Category = "damage")
		float impulse = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
