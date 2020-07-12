// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "square/upDownSquare.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "gameInstance/kusaGameInstance.h"
#include "square/upDownSquare.h"
#include "Math/UnrealMathUtility.h"
#include "square/Square_rot.h"
#include "square/Square_size.h"


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

	int WhatToSelect = 7;

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


				WhatToSelect = (int)FMath::FRandRange(1, 8);


				if (WhatToSelect == 1) {
					int drawpos = xpos;
					//random number
					for (int i = 0; i < 4; i++) {
						//updown
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
				else if (WhatToSelect == 2) {
					//rotating
					int drawpos = xpos+500;
					bool rx, ry, rz;
					//random number
					for (int i = 0; i < 1; i++) {
						//updown
						int ypos = FMath::FRandRange(-1000, -600);
						int inc = (int)(ypos / 2);
						inc *= -1;
						rx = ry = rz = false;
						if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
							rx = true;
						}
						if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
							rz = true;
						}
						ry = true;
						
						float speed = FMath::FRandRange(100, 200);

						for (int j = 0; j < 5; j++) {
							if (sq_rot) {
								ASquare_rot* a1 = world->SpawnActor<ASquare_rot>(sq_rot, FVector(drawpos, ypos+200, 0), FRotator(0), spawnPara);
								a1->SetRotSetUp(rx, ry, rz, speed);
								blocks.Push(a1);

							}
							ypos += inc;
						}
						drawpos += 500;
					}

				}
				else if (WhatToSelect == 3) {
					int drawpos = xpos+500;
					//random number
					for (int i = 0; i < 1; i++) {
						//updown
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
						drawpos += 500;
					}
				}
				else if (WhatToSelect == 4) {
					int drawpos = xpos;
					//random number
					for (int i = 0; i < 3; i++) {
						//updown
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
						drawpos += 330;
					}
				}
				else if (WhatToSelect == 5) {
					//rotating
					int drawpos = xpos;
					bool rx, ry, rz;
					//random number
					for (int i = 0; i < 3; i++) {
						//updown
						int ypos = FMath::FRandRange(-1000, -600);
						int inc = (int)(ypos / 2);
						inc *= -1;
						rx = ry = rz = false;
						if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
							rx = true;
						}
						if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
							rz = true;
						}
						ry = true;

						float speed = FMath::FRandRange(100, 200);

						for (int j = 0; j < 5; j++) {
							if (sq_rot) {
								ASquare_rot* a1 = world->SpawnActor<ASquare_rot>(sq_rot, FVector(drawpos, ypos + 200, 0), FRotator(0), spawnPara);
								a1->SetRotSetUp(rx, ry, rz, speed);
								blocks.Push(a1);

							}
							ypos += inc;
						}
						drawpos += 330;
					}

				}
				else if (WhatToSelect == 6) {
					//rotating
					
					bool rx, ry, rz;

					rx = ry = rz = false;
					if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
						rz = true;
					}
					if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
						ry = true;
					}
					rx = true;

					int ypos = -500;

					float speed = FMath::FRandRange(1, 4);
					for (int i = 0; i < 3; i++) {
						if (sq_Size) {
							ASquare_size* a1 = world->SpawnActor<ASquare_size>(sq_Size, FVector(xpos + 500, ypos, 0), FRotator(0), spawnPara);
							a1->SizeSetUp(rx, ry, rz, speed, 3);
							blocks.Push(a1);

						}
						ypos += 500;
					}
				}
				else if (WhatToSelect == 7) {
				
					bool rx, ry, rz;

					rx = ry = rz = false;
					if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
						rz = true;
					}
					if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
						ry = true;
					}
					rx = true;


					float speed = FMath::FRandRange(1, 4);
				
						if (sq_Size) {
							ASquare_size* a1 = world->SpawnActor<ASquare_size>(sq_Size, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
							a1->SizeSetUp(rx, ry, rz, speed, 3);
							blocks.Push(a1);

						}
				
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

