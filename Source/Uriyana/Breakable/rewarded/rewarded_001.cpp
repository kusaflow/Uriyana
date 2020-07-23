// Fill out your copyright notice in the Description page of Project Settings.


#include "rewarded_001.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../../ThrowBall.h"
#include "../../gameInstance/kusaGameInstance.h"

// Sets default values
Arewarded_001::Arewarded_001()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	RootComponent = block;

	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	destr->SetupAttachment(RootComponent);

	destr->OnComponentHit.AddDynamic(this, &Arewarded_001::OnCompHit);

	broken = false;
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

void Arewarded_001 :: OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit) {

	

	AThrowBall* ball = Cast<AThrowBall>(OtherActor);

	if (ball) {
		//destr->AddRadialForce(destr->GetComponentLocation(), 1000, -50000, ERadialImpulseFalloff::RIF_Linear, true);
		destr->ApplyRadiusDamage(5000000.0, destr->GetComponentLocation(), 10000.0, 50000.0, true);
		if (!broken) {
			UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
			if (gameInst) {
				gameInst->Health += 50;
				broken = true;

				if (gameInst->Health >= 1000) {
					gameInst->Health = 1000;
				}
			}
		}
	}
	
}