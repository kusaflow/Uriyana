// Fill out your copyright notice in the Description page of Project Settings.


#include "Triangle_floor.h"
#include "Components/BoxComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ATriangle_floor::ATriangle_floor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	RootComponent = box;

	block1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block1"));
	block1->SetupAttachment(RootComponent);

	block2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block2"));
	block2->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATriangle_floor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriangle_floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

