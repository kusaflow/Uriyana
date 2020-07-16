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

	UPROPERTY(BlueprintReadOnly, Category= "kusavar")
	float next_Milestone;


	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> walkPath;

	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> walls;

	//square=====================================================================
	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class AActor> sq_upDown;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class AActor> sq_floor;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class ASquare_rot> sq_rot;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class ASquare_size> sq_Size;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class ASquare_BigRot> sq_Big_Rot;

	UPROPERTY(EditDefaultsOnly, category = "Square")
	TSubclassOf<class Asq_floor> sq_floor_pro;

//===========================================triangle=================================================
	UPROPERTY(EditDefaultsOnly, category = "Triangle")
	TSubclassOf<class ATriangle_floor> tri_floor;


	int Theme;
	int Theme_Duration;
	int floorType;
	int floorType_Duration;
	int wallType;
	int wallType_Duration;
	int BreakPointType;


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

	int breakPoint = 10;
	int PrefObj;

	bool prevIsBreak = false;

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
