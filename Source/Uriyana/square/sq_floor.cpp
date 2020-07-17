// Fill out your copyright notice in the Description page of Project Settings.


#include "sq_floor.h"

// Sets default values
Asq_floor::Asq_floor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block"));
	RootComponent = block;
}

// Called when the game starts or when spawned
void Asq_floor::BeginPlay()
{
	Super::BeginPlay();

	znum = -1;
	
}

// Called every frame
void Asq_floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void Asq_floor :: set_znum(float z) {
	znum = z;
	FVector orgSize = block->GetComponentScale();
	block->SetWorldScale3D(FVector(orgSize.X, orgSize.Y, z));
}
