// Fill out your copyright notice in the Description page of Project Settings.


#include "Glass_001.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../ThrowBall.h"
#include "../mainChar.h"
#include "../gameInstance/kusaGameInstance.h"
 

// Sets default values
AGlass_001::AGlass_001()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	RootComponent = destr;

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	block->SetupAttachment(destr);


	block->OnComponentBeginOverlap.AddDynamic(this, &AGlass_001::OnOverlapBegin);

	block->SetGenerateOverlapEvents(true);

	broken = false;
	destr->SetEnableGravity(false);

	basedamage = 5000000.0;
	impulseRadius = 10000.0;
	impulse = 50000.0;
	
}

// Called when the game starts or when spawned
void AGlass_001::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGlass_001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!broken) {
		if (inRight)
			destr->AddWorldOffset(FVector(0,300 *DeltaTime, 0));
		else 	
			destr->AddWorldOffset(FVector(0, -300 * DeltaTime, 0));

		if (destr->GetComponentLocation().Y > 1000) {
			inRight = false;
		}
		else if (destr->GetComponentLocation().Y < -1000) {
			inRight = true;
		}
	}

}

void AGlass_001 :: OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	AmainChar* mainCh = Cast<AmainChar>(OtherActor);

	if (mainCh) {
		if (!broken) {
			UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());

			if (gameInst) {
				gameInst->Health -= 100;
				gameInst->bGotHit = true;
				broken = true;
			}
		}
		return;
	}


	AThrowBall* ball = Cast<AThrowBall>(OtherActor);

	if (ball) {
		//destr->AddRadialForce(destr->GetComponentLocation(), 1000, -50000, ERadialImpulseFalloff::RIF_Linear, true);
		if (!broken) {
			broken = true;
			destr->ApplyRadiusDamage(basedamage, destr->GetComponentLocation(), impulseRadius, impulse, true);

			destr->SetEnableGravity(true);


		}
	}
	else {
		destr->SetEnableGravity(true);
		broken = true;
	}

	
}
