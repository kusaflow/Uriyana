// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "square/upDownSquare.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "gameInstance/kusaGameInstance.h"
#include "square/upDownSquare.h"
#include "Math/UnrealMathUtility.h"


// Sets default values
ALevelManager::ALevelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	xpos = -50000;

}

ALevelManager :: ~ALevelManager() {
	/*while (LB_array.Num() != 0) {
		L_actors = LB_array.Pop();

		while (L_actors.Num() != 0) {
			L_actors.Pop()->Destroy();
		}
	}*/
}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	initBlocks();
	
}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	float playerPosX = gameInst->playerXpos;

	if (playerPosX >= next_Milestone) {
		UpdateLevel();
	}
}


void ALevelManager :: UpdateLevel() {
	CreateLevelBlock();

	next_Milestone += 1000;
	
	popBlock();
	
}

void ALevelManager :: popBlock() {
	if (LB_array.IsEmpty()) {
		return;
	}
	TArray<AActor*> rem;
	LB_array.Peek(rem);
	LB_array.Pop();
	
	UE_LOG(LogTemp, Warning, TEXT("%d"), rem.Num());
	while (rem.Num() != 0) {
		rem.Pop()->Destroy();
	}


}

void ALevelManager::initBlocks() {
	
	for (int i = 0; i < 10; i++) {
		CreateLevelBlock();
		//UE_LOG(LogTemp, Warning, TEXT("down"));
		if (i == 2) {
			next_Milestone = xpos;
		}
	}
}

void ALevelManager::CreateLevelBlock() {
	TArray<AActor*> blocks;

	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	UWorld* world = GetWorld();
	if (world) {

		if (walkPath) {
			AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos, 0, 200), FRotator(0), spawnPara);
			blocks.Push(sp);
		}

		//Area Square
		if (lvl_G == 1) {
			//manage square circle triangle 
			if (lvl_T == 1) {
				//manage sqaure
				
				//floor
				if (sq_floor) {
					AActor* floor = world->SpawnActor<AActor>(sq_floor, FVector(xpos, 0, -200), FRotator(0), spawnPara);
					blocks.Push(floor);
				}
				int drawpos = xpos;
				//random number
				for (int i = 0; i < 4; i++) {
					int ypos = (int)FMath::FRandRange(-300, -1000);
					int inc = (int)(ypos / 2);
					inc *= -1;
					for (int j = 0; j < 5; j++) {
						if (sq_upDown) {
							AActor* a1 = world->SpawnActor<AActor>(sq_upDown, FVector(drawpos, ypos, 0), FRotator(0), spawnPara);
							blocks.Push(a1);
						}
						ypos += inc;
					}
					drawpos += 250;
				}


			}
		}


		





		//Area Sqare End

		//UE_LOG(LogTemp, Warning, TEXT("down"));

	}
	xpos += 1000;
	//UE_LOG(LogTemp, Warning, TEXT("%d"), blocks.Num());
	LB_array.Enqueue(blocks);
}

