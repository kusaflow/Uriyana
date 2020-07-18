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
#include "square/Square_BigRot.h"
#include "square/sq_floor.h"
#include "triangle/Triangle_floor.h"
  


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

	next_Milestone += 1000;
	
	CreateLevelBlock();
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
		//Area Square
		if (Theme_Duration > 0) {
			if (dissolve <= 0) {
				if (floorType_Duration > 0) {

					if (walkPath) {
						AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 500, 0, 200), FRotator(0), spawnPara);
						blocks.Push(sp);
					}
					//=====close box

					if (lvl_G == 1) {
						//normal
						if (floorType == 1) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 4, 1));
								aa->set_znum(3);
								blocks.Push(aa);
							}
						}
						//narrow
						else if (floorType == 2) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 2, 1));
								aa->set_znum(3);
								blocks.Push(aa);
							}
						}
						//wide
						else if (floorType == 3) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 10, 1));
								aa->set_znum(3);
								blocks.Push(aa);
							}
						}

						//wide narrow normal
						else if (floorType == 4) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, FMath::FRandRange(1,10), 1));
								aa->set_znum(3);
								blocks.Push(aa);
							}
						}
						//normal error 33%
						else if (floorType == 5) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 4, 1));
								aa->set_znum(3);
								blocks.Push(aa);
								int xt = xpos;
								int yt = -500;
								for (int i = 0; i < 5; i++) {
									yt = -500;
									for (int j = 0; j < 5; j++) {
										if ((int)(FMath::FRandRange(0, 50)) % 3 == 0) {
											Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
											a1->set_znum(FMath::FRandRange(3.1, 3.5));
											blocks.Push(a1);
										}
										yt += 200;
									}
									xt += 200;
								}
							}
						}
						//normal error 20%
						else if (floorType == 6) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 4, 1));
								aa->set_znum(3);
								blocks.Push(aa);
								int xt = xpos;
								int yt = -500;
								for (int i = 0; i < 6; i++) {
									yt = -500;
									for (int j = 0; j < 5; j++) {
										if ((int)(FMath::FRandRange(0, 50)) % 5 == 0) {
											Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
											a1->set_znum(FMath::FRandRange(3.1, 3.5));
											blocks.Push(a1);
										}
										yt += 200;
									}
									xt += 200;
								}
							}
						}
						//normal error 10%
						else if (floorType == 7) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 4, 1));
								aa->set_znum(3);
								blocks.Push(aa);
								int xt = xpos;
								int yt = -500;
								for (int i = 0; i < 5; i++) {
									yt = -500;
									for (int j = 0; j < 5; j++) {
										if ((int)(FMath::FRandRange(0, 50)) % 10 == 0) {
											Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
											a1->set_znum(FMath::FRandRange(3.1, 3.5));
											blocks.Push(a1);
										}
										yt += 200;
									}
									xt += 200;
								}
							}
						}
						//narrow error 33%
						else if (floorType == 8) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 2, 1));
								aa->set_znum(3);
								blocks.Push(aa);
								int xt = xpos;
								int yt = -100;
								for (int i = 0; i < 5; i++) {
									yt = -100;
									for (int j = 0; j < 2; j++) {
										if ((int)(FMath::FRandRange(0, 50)) % 3 == 0) {
											Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
											a1->set_znum(FMath::FRandRange(3.1, 3.3));
											blocks.Push(a1);
										}
										yt += 200;
									}
									xt += 200;
								}
							}
						}
						//narrow error 20%
						else if (floorType == 9) {
							if (sq_floor_pro) {
								Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
								aa->SetActorScale3D(FVector(5, 2, 1));
								aa->set_znum(3);
								blocks.Push(aa);
								int xt = xpos;
								int yt = -100;
								for (int i = 0; i < 5; i++) {
									yt = -100;
									for (int j = 0; j < 2; j++) {
										if ((int)(FMath::FRandRange(0, 50)) % 5 == 0) {
											Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
											a1->set_znum(FMath::FRandRange(3.1, 3.3));
											blocks.Push(a1);
										}
										yt += 200;
									}
									xt += 200;
								}
							}
						}
						//narrow error 10%
						else if (floorType == 10) {
						if (sq_floor_pro) {
							Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
							aa->SetActorScale3D(FVector(5, 2, 1));
							aa->set_znum(3);
							blocks.Push(aa);
							int xt = xpos;
							int yt = -100;
							for (int i = 0; i < 5; i++) {
								yt = -100;
								for (int j = 0; j < 2; j++) {
									if ((int)(FMath::FRandRange(0, 50)) % 11 == 0) {
										Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
										a1->set_znum(FMath::FRandRange(3.1, 3.3));
										blocks.Push(a1);
									}
									yt += 200;
								}
								xt += 200;
							}
						}
						}
						//wide error 33%
						else if (floorType == 11) {
						if (sq_floor_pro) {
							Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
							aa->SetActorScale3D(FVector(5, 10, 1));
							aa->set_znum(3);
							blocks.Push(aa);
							int xt = xpos;
							int yt = -900;
							for (int i = 0; i < 5; i++) {
								yt = -900;
								for (int j = 0; j < 10; j++) {
									if ((int)(FMath::FRandRange(0, 50)) % 3 == 0) {
										Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
										a1->set_znum(FMath::FRandRange(3.1, 3.3));
										blocks.Push(a1);
									}
									yt += 200;
								}
								xt += 200;
							}
						}
						}
						//wide error 20%
						else if (floorType == 12) {
						if (sq_floor_pro) {
							Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
							aa->SetActorScale3D(FVector(5, 10, 1));
							aa->set_znum(3);
							blocks.Push(aa);
							int xt = xpos;
							int yt = -900;
							for (int i = 0; i < 5; i++) {
								yt = -900;
								for (int j = 0; j < 10; j++) {
									if ((int)(FMath::FRandRange(0, 50)) % 5 == 0) {
										Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
										a1->set_znum(FMath::FRandRange(3.1, 3.3));
										blocks.Push(a1);
									}
									yt += 200;
								}
								xt += 200;
							}
						}
						}
						//wide error 10%
						else if (floorType == 13) {
						if (sq_floor_pro) {
							Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
							aa->SetActorScale3D(FVector(5, 10, 1));
							aa->set_znum(3);
							blocks.Push(aa);
							int xt = xpos;
							int yt = -900;
							for (int i = 0; i < 5; i++) {
								yt = -900;
								for (int j = 0; j < 10; j++) {
									if ((int)(FMath::FRandRange(0, 50)) % 11 == 0) {
										Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, yt, 0), FRotator(0, 0, 0), spawnPara);
										a1->set_znum(FMath::FRandRange(3.1, 3.3));
										blocks.Push(a1);
									}
									yt += 200;
								}
								xt += 200;
							}
						}
						}
						//1|1|1|1|1|1|i
						else if (floorType == 14) {
							if (sq_floor_pro) {
								float  xt = xpos;
								for (int i = 0; i < 6; i++) {
									
									Asq_floor* a1 = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xt, 0, 0), FRotator(0, 0, 0), spawnPara);
									if (i%2==0)
										a1->SetActorScale3D(FVector(0.83f,1,1));
									else
										a1->SetActorScale3D(FVector(0.83f, 3, 1));
									a1->set_znum(3);
									blocks.Push(a1);
									
									
									xt += 200*0.83f;
								}
							}
						}


					}

					if (lvl_G == 100) {
						//manage square circle triangle 
						if (lvl_T == 1) {
							//manage sqaure

							//floor
							if (sq_floor) {
								AActor* floor = world->SpawnActor<AActor>(sq_floor, FVector(xpos + 500, 0, -200), FRotator(0), spawnPara);
								floor->SetActorScale3D(FVector(5, 10, .5f));
								blocks.Push(floor);
							}


							//WhatToSelect = (int)FMath::FRandRange(1, 8);
							WhatToSelect = 9;

							//floor----------------------------------------------------------------------------------
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
								int drawpos = xpos + 500;
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
											ASquare_rot* a1 = world->SpawnActor<ASquare_rot>(sq_rot, FVector(drawpos, ypos + 200, 0), FRotator(0), spawnPara);
											a1->SetRotSetUp(rx, ry, rz, speed);
											blocks.Push(a1);

										}
										ypos += inc;
									}
									drawpos += 500;
								}

							}
							else if (WhatToSelect == 3) {
								int drawpos = xpos + 500;
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
							else if (WhatToSelect == 8) {
								int xtemp = xpos;
								for (int i = 0; i < 5; i++) {
									int ytemp = -500;
									for (int j = 0; j < 6; j++) {
										if (sq_floor_pro) {
											Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xtemp, ytemp, 0), FRotator(0, 0, 0), spawnPara);
											//floor->SetActorScale3D(FVector(5, 10, .5f));
											aa->set_znum(3);
											blocks.Push(aa);
										}
										ytemp += 200;
									}
									xtemp += 200;
								}
							}
							//big width same surface floor
							else if (WhatToSelect == 9) {
								if (sq_floor_pro) {
									Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos + 500, 0, 0), FRotator(0, 0, 0), spawnPara);
									aa->SetActorScale3D(FVector(5, 10, 1));
									aa->set_znum(3);
									blocks.Push(aa);
								}

							}


							//wall---------------------------------------------------------------------------------------

						}

						else if (lvl_T == 3) {
							if (tri_floor) {
								AActor* floor = world->SpawnActor<AActor>(tri_floor, FVector(xpos, 0, -200), FRotator(0, 90, 0), spawnPara);
								//floor->SetActorScale3D(FVector(5, 10, .5f));
								blocks.Push(floor);
							}
						}
					}

					xpos += 1000;
					floorType_Duration--;

				}
				//----------------------------------------------------------------------------------------------------------------
				else {

					if (walkPath) {
						AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 500, 0, 200), FRotator(0), spawnPara);
						sp->SetActorScale3D(FVector(5, 5, 0.5f));
						blocks.Push(sp);
					}

					if (lvl_G == 1){
						//normal
						if (floorType == 1 || floorType == 4 || floorType == 5 || floorType == 6 || floorType == 7) {
							int yt = -700;
							for (int i = 0; i < 8; i++) {
								if (sq_floor_pro) {
									Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos , yt, 0), FRotator(0, 0, 0), spawnPara);
									aa->SetActorScale3D(FVector(1, 1, 1));
									aa->set_znum(FMath::FRandRange(3.1, 3.5));
									blocks.Push(aa);
								}
								yt += 200;
							}
						}
						//narrow
						else if (floorType == 2 || floorType == 8 || floorType == 9 || floorType == 10) {
							int yt = -100;
							for (int i = 0; i < 2; i++) {
								if (sq_floor_pro) {
									Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos , yt, 0), FRotator(0, 0, 0), spawnPara);
									aa->SetActorScale3D(FVector(1, 1, 1));
									aa->set_znum(FMath::FRandRange(3.1, 3.5));
									blocks.Push(aa);
								}
								yt += 200;
							}
						}
						//wide
						else if (floorType == 3 || floorType == 11 || floorType == 12 || floorType == 13) {
							int yt = -900;
							for (int i = 0; i < 10; i++) {
								if (sq_floor_pro) {
									Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos , yt, 0), FRotator(0, 0, 0), spawnPara);
									aa->SetActorScale3D(FVector(1, 1, 1));
									aa->set_znum(FMath::FRandRange(3.1, 3.5));
									blocks.Push(aa);
								}
								yt += 200;
							}
						}
						//y size = 3
						if (floorType == 14) {
							int yt = -300;
							for (int i = 0; i < 4; i++) {
								if (sq_floor_pro) {
									Asq_floor* aa = world->SpawnActor<Asq_floor>(sq_floor_pro, FVector(xpos, yt, 0), FRotator(0, 0, 0), spawnPara);
									aa->SetActorScale3D(FVector(1, 1, 1));
									aa->set_znum(FMath::FRandRange(3.1, 3.5));
									blocks.Push(aa);
								}
								yt += 200;
							}
						}
						
					}

					if (lvl_G == 1000) {
						//manage square circle triangle 
						if (lvl_T == 1) {
							//square
							//WhatToSelect = (int)FMath::FRandRange(1, 8);

							if (sq_floor) {
								AActor* floor = world->SpawnActor<AActor>(sq_floor, FVector(xpos + 500, 0, -200), FRotator(0), spawnPara);
								floor->SetActorScale3D(FVector(10, 10, .5f));
								blocks.Push(floor);
							}

							WhatToSelect = 1;

							if (WhatToSelect == 1) {
								if (sq_floor) {
									AActor* aa = world->SpawnActor<AActor>(sq_floor, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
									aa->SetActorScale3D(FVector(FMath::FRandRange(1, 5), 7, FMath::FRandRange(1.2f, 1.7f)));
									blocks.Push(aa);
								}
							}

							if ((int)(FMath::FRandRange(0, 50)) % 2 == 0) {
								/*if (sq_Big_Rot) {
									AActor* aa = world->SpawnActor<AActor>(sq_Big_Rot, FVector(xpos, 0, 0), FRotator(0), spawnPara);
									blocks.Push(aa);
								}
								*/
							}


						}


					}
					floorType = 14;//FMath::FRandRange(1, 14);
					floorType_Duration = FMath::FRandRange(3, 10);

					xpos += 1000;

					//UE_LOG(LogTemp, Warning, TEXT("down"));
				}
				//Area Sqare End
			}
			else {
				dissolve--;
			}
		}
		else {
			//SetTheme
		}


	}
	//UE_LOG(LogTemp, Warning, TEXT("%d"), blocks.Num());
	LB_array.Enqueue(blocks);
}

