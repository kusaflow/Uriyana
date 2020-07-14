// Fill out your copyright notice in the Description page of Project Settings.


#include "Square_BigRot.h"
#include "Components/BoxComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASquare_BigRot::ASquare_BigRot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	RootComponent = box;

	block1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block1"));
	block1->SetupAttachment(RootComponent);

	block2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block2"));
	block2->SetupAttachment(RootComponent);
	
	block3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block3"));
	block3->SetupAttachment(RootComponent);
	
	block4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block4"));
	block4->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void ASquare_BigRot::BeginPlay()
{
	Super::BeginPlay();
	box->SetWorldRotation(FRotator(0,0, FMath::FRandRange(0,180)));
	
}

// Called every frame
void ASquare_BigRot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	box->AddWorldRotation(FRotator(0, 0,10 * DeltaTime));;

}

