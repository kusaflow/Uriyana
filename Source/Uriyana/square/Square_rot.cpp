// Fill out your copyright notice in the Description page of Project Settings.


#include "Square_rot.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASquare_rot::ASquare_rot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block"));
	RootComponent = block;

	inX = inY = inZ = false;

	//inY = true;
	
}

// Called when the game starts or when spawned
void ASquare_rot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquare_rot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (inX) {
		block->AddWorldRotation(FRotator(0,0, speed * DeltaTime));;
	}
	if (inY) {
		block->AddWorldRotation(FRotator(speed * DeltaTime, 0, 0));;
	}
	if (inZ) {
		block->AddWorldRotation(FRotator(0, speed * DeltaTime, 0));;
	}
}

void ASquare_rot::SetRotSetUp(bool x, bool y, bool z, float s) {
	inX = x;
	inY = y;
	inZ = z;
	speed = s;
}

