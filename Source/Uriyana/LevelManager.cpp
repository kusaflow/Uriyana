// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "square/upDownSquare.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "gameInstance/kusaGameInstance.h"


// Sets default values
ALevelManager::ALevelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	xpos = 0;

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
	TArray<AActor*> *rem = LB_array.Peek();
	LB_array.Pop();

	//UE_LOG(LogTemp, Warning, TEXT("%d"), rem->Num());
	while (rem->Num() != 0) {
		//rem->Pop()->Destroy();

	}


}

void ALevelManager::initBlocks() {
	
	for (int i = 0; i < 4; i++) {
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
		AActor* sp = world->SpawnActor<AActor>(levelBlock, FVector(xpos, 0, 0), FRotator(0), spawnPara);
		xpos += 1000;
		blocks.Push(sp);
		blocks.Push(sp);
		//UE_LOG(LogTemp, Warning, TEXT("down"));

	}
	UE_LOG(LogTemp, Warning, TEXT("%d"), blocks.Num());
	LB_array.Enqueue(blocks);
}

