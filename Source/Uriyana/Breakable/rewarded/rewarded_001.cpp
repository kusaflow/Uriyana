// Fill out your copyright notice in the Description page of Project Settings.


#include "rewarded_001.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../../ThrowBall.h"

// Sets default values
Arewarded_001::Arewarded_001()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	RootComponent = block;

	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	destr->SetupAttachment(RootComponent);

	block->OnComponentBeginOverlap.AddDynamic(this, &Arewarded_001::boxOverlap);
}

// Called when the game starts or when spawned
void Arewarded_001::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Arewarded_001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Arewarded_001 :: boxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	AThrowBall* ball = Cast<AThrowBall>(OtherActor);

	if (ball) {
		destr->AddRadialForce(destr->GetComponentLocation(), 1000, -50000, ERadialImpulseFalloff::RIF_Linear, true);
	}
	
}