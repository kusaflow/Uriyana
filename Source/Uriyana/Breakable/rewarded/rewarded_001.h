// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "rewarded_001.generated.h"

UCLASS()
class URIYANA_API Arewarded_001 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Arewarded_001();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* block;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDestructibleComponent* destr;

	bool broken = false;

	UPROPERTY(EditDefaultsOnly, category = "sound")
	class USoundCue* S_breaking;

	UPROPERTY(EditDefaultsOnly, category = "sound")
	class USoundCue* S_impact;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	
};
