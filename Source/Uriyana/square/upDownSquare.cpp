// Fill out your copyright notice in the Description page of Project Settings.


#include "upDownSquare.h"

// Sets default values
AupDownSquare::AupDownSquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block"));
	RootComponent = block;

	upLimit = 200;
	downLimit = 200;
	bMovingUp = true;
	speed = 500;

}

// Called when the game starts or when spawned
void AupDownSquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AupDownSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMovingUp) {
		block->AddRelativeLocation(FVector(0,0,speed * DeltaTime));
		//UE_LOG(LogTemp, Warning, TEXT("up"));
		if (block->GetRelativeLocation().Z >= upLimit) {
			bMovingUp = false;
		}
	}else{
		block->AddRelativeLocation(FVector(0, 0, -1 * speed * DeltaTime));
		//UE_LOG(LogTemp, Warning, TEXT("down"));
		if (block->GetRelativeLocation().Z <= -1*downLimit) {
			bMovingUp = true;
		}
	}

}

