// Fill out your copyright notice in the Description page of Project Settings.


#include "triangle_rot.h"
#include "Components/BoxComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
Atriangle_rot::Atriangle_rot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	RootComponent = box;

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block"));
	block->SetupAttachment(RootComponent);

	inX = inY = inZ = false;
	speed = 100;

	inX = true;
}

// Called when the game starts or when spawned
void Atriangle_rot::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void Atriangle_rot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (inX) {
		box->AddWorldRotation(FRotator(0, 0, speed * DeltaTime));;
	}
	if (inY) {
		box->AddWorldRotation(FRotator(speed * DeltaTime, 0, 0));;
	}
	if (inZ) {
		box->AddWorldRotation(FRotator(0, speed * DeltaTime, 0));;
	}
}

void Atriangle_rot::SetRotSetUp(bool x, bool y, bool z, float s) {
	inX = x;
	inY = y;
	inZ = z;
	speed = s;
}
