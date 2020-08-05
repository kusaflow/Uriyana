// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "noGravityGlass.generated.h"

UCLASS()
class URIYANA_API AnoGravityGlass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AnoGravityGlass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* block;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDestructibleComponent* destr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "kusaVar", meta = (AllowPrivateAccess = "true"))
	bool broken = false;

	UPROPERTY(EditAnywhere, Category = "damage")
	float basedamage = 0;

	UPROPERTY(EditAnywhere, Category = "damage")
	float impulseRadius = 0;

	UPROPERTY(EditAnywhere, Category = "damage")
	float impulse = 0;

	UPROPERTY(EditDefaultsOnly, category = "sound")
	class USoundCue* soundFX;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void onFrac(const FVector& HitPoint, const FVector& HitDirection);



};
