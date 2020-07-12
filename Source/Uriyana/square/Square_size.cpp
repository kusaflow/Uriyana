// Fill out your copyright notice in the Description page of Project Settings.


#include "Square_size.h"

// Sets default values
ASquare_size::ASquare_size()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block"));
	RootComponent = block;

	inX = inY = inZ = false;

	Limit = 3;
	currentSize = 0;
	speed = 2;
}

// Called when the game starts or when spawned
void ASquare_size::BeginPlay()
{
	Super::BeginPlay();

	if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
		inX = true;
	}
	if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
		inY = true;
	}
	if ((int)FMath::FRandRange(0, 500) % 2 == 0) {
		inZ = true;
	}	
}

// Called every frame
void ASquare_size::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMovingInpos) {
		currentSize += speed * DeltaTime;

		if (currentSize >= Limit) {
			bMovingInpos = false;
		}
	}
	else {
		currentSize -= speed * DeltaTime;

		if (currentSize < 0.1f) {
			bMovingInpos = true;
		}
	}
	FVector org = block->GetComponentScale();
	block->SetWorldScale3D(FVector(
		inX ? currentSize : org.X,
		inY ? currentSize : org.Y,
		inZ ? currentSize : org.Z
	));
	

}

void ASquare_size::SizeSetUp(bool x, bool y, bool z, float s, float limit) {
	inX = x;
	inY = y;
	inZ = z;
	speed = s;
	Limit = limit;
}

