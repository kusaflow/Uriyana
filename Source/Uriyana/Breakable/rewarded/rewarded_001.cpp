// Fill out your copyright notice in the Description page of Project Settings.


#include "rewarded_001.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../../ThrowBall.h"
#include "Kismet/GameplayStatics.h" 	
#include "Sound/SoundCue.h"
#include "../../gameInstance/kusaGameInstance.h"

// Sets default values
Arewarded_001::Arewarded_001()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	RootComponent = destr;

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	block->SetupAttachment(RootComponent);

	block->OnComponentBeginOverlap.AddDynamic(this, &Arewarded_001::OnOverlapBegin);

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

void Arewarded_001 ::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	

	AThrowBall* ball = Cast<AThrowBall>(OtherActor);

	if (ball) {
		//destr->AddRadialForce(destr->GetComponentLocation(), 1000, -50000, ERadialImpulseFalloff::RIF_Linear, true);
		if (!broken) {
			destr->ApplyRadiusDamage(5000000.0, destr->GetComponentLocation(), 10000.0, 50000.0, true);

			if (S_impact)
				UGameplayStatics::SpawnSoundAtLocation(this, S_impact, RootComponent->GetComponentLocation());
				
			if (S_breaking)
				UGameplayStatics::SpawnSoundAtLocation(this, S_breaking, RootComponent->GetComponentLocation());

			UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
			if (gameInst) {
				gameInst->Health += 40;
				broken = true;

				if (gameInst->Health >= 1000) {
					gameInst->Health = 1000;
				}
			}
		}
	}
	
}

