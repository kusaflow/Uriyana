// Fill out your copyright notice in the Description page of Project Settings.


#include "them1_spinningGlass.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../ThrowBall.h"
#include "../gameInstance/kusaGameInstance.h"

// Sets default values
Athem1_spinningGlass::Athem1_spinningGlass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	top = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("base"));
	RootComponent = top;

	destr1 = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy1"));
	destr1->SetupAttachment(RootComponent);

	block1 = CreateDefaultSubobject<UBoxComponent>(TEXT("block1"));
	block1->SetupAttachment(destr1);

	///////////

	destr2 = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy2"));
	destr2->SetupAttachment(RootComponent);

	block2 = CreateDefaultSubobject<UBoxComponent>(TEXT("block2"));
	block2->SetupAttachment(destr2);

	///////////

	destr3 = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy3"));
	destr3->SetupAttachment(RootComponent);

	block3 = CreateDefaultSubobject<UBoxComponent>(TEXT("block3"));
	block3->SetupAttachment(destr3);


	///////////

	destr4 = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy4"));
	destr4->SetupAttachment(RootComponent);

	block4 = CreateDefaultSubobject<UBoxComponent>(TEXT("block4"));
	block4->SetupAttachment(destr1);



	basedamage = 5000000.0;
	impulseRadius = 10000.0;
	impulse = 50000.0;


	broken = false;
}

// Called when the game starts or when spawned
void Athem1_spinningGlass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Athem1_spinningGlass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Athem1_spinningGlass::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	

}
