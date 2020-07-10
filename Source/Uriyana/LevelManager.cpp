// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "square/upDownSquare.h"

// Sets default values
ALevelManager::ALevelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	xpos = 0;

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

}


void ALevelManager :: UpdateLevel() {

}

void ALevelManager::initBlocks() {
	
	for (int i = 0; i < 20; i++) {
		CreateLevelBlock();
		UE_LOG(LogTemp, Warning, TEXT("down"));

		LB_array.Push(L_actors);
	}
}

void ALevelManager::CreateLevelBlock() {
	while (L_actors.Num() != 0) {
		L_actors.Pop();
	}
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	UWorld* world = GetWorld();
	if (world) {
		AActor* sp = world->SpawnActor<AActor>(levelBlock, FVector(xpos, 0, 0), FRotator(0), spawnPara);
		xpos += 1000;
		L_actors.Push(sp);
	}
}

