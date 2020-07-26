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

	//---------------------------------Rewarded============================================================
	UPROPERTY(EditDefaultsOnly, category = "Rewarded")
	TSubclassOf<class AActor> reward;

	//--------------------------Theme 1 breakable------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, category = "T1_Breakable")
	TSubclassOf<class AActor> T1_breakable;

	UPROPERTY(EditDefaultsOnly, category = "T1_Breakable")
	TSubclassOf<class AActor> T2_breakable;

	UPROPERTY(EditDefaultsOnly, category = "T1_Breakable")
	TSubclassOf<class AActor> T3_breakable;

	UPROPERTY(EditDefaultsOnly, category = "T1_Breakable")
	TSubclassOf<class AActor> T4_breakable;

	UPROPERTY(EditDefaultsOnly, category = "T1_Breakable")
	TSubclassOf<class AActor> T5_breakable; 

	//theme 1 big models

	UPROPERTY(EditDefaultsOnly, category = "T1_Big_Breakable")
	TSubclassOf<class AActor> T1_b1;

	UPROPERTY(EditDefaultsOnly, category = "T1_Big_Breakable")
	TSubclassOf<class AActor> T1_b2;

	UPROPERTY(EditDefaultsOnly, category = "T1_Big_Breakable")
	TSubclassOf<class AActor> T1_b3;

	UPROPERTY(EditDefaultsOnly, category = "T1_Big_Breakable")
	TSubclassOf<class AActor> T1_b4;

	UPROPERTY(EditDefaultsOnly, category = "T1_Big_Breakable")
	TSubclassOf<class AActor> T1_b5;

	
	TSubclassOf<class AActor> breakableActor;




	int Theme =1;
	int Theme_Duration=10;

	int floorType = 1;
	int floorType_Duration =10;

	int wallType;
	int wallType_Duration;
	//int BreakPointType;

	int dissolve = -10;

	bool tutDone = false;

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

	int PrefObj;
	
	///rewarded 
	int rewardedTimeOut ;
	int RewardToDraw;

	int breakableTimeout;
	int breakableToDraw;


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
