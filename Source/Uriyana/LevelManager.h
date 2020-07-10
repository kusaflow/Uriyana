// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelManager.generated.h"

UCLASS()
class URIYANA_API ALevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelManager();
	~ALevelManager();

	
	TQueue<TArray<AActor*>> LB_array;

	float next_Milestone;


	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> walkPath;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class AActor> sq_upDown;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class AActor> sq_floor;


	int64 xpos;

	int lvl_G =1;
	/* 
	lvl_G ----------  includes
	1				 square / circle / triangle

	*/
	int lvl_T = 1;
	/*
	lvl_G
	1
		lvl_T		type
		1			square
		2			cicle
		3			triagle
	================================================================

	*/


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateLevel();

	void initBlocks();

	void CreateLevelBlock();

	void popBlock();

};
