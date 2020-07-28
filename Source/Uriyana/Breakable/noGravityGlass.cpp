// Fill out your copyright notice in the Description page of Project Settings.


#include "noGravityGlass.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../ThrowBall.h"
#include "../gameInstance/kusaGameInstance.h"
#include "../mainChar.h"

// Sets default values
AnoGravityGlass::AnoGravityGlass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	RootComponent = destr;

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	block->SetupAttachment(RootComponent);

	block->OnComponentBeginOverlap.AddDynamic(this, &AnoGravityGlass::OnOverlapBegin);

	block->SetGenerateOverlapEvents(true);

	broken = false;
	destr->SetEnableGravity(false);

	destr->OnComponentFracture.AddDynamic(this, &AnoGravityGlass :: onFrac);

	basedamage = 5000000.0;
	impulseRadius = 10000.0;
	impulse = 50000.0;

}

// Called when the game starts or when spawned
void AnoGravityGlass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AnoGravityGlass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AnoGravityGlass::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

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
		destr->DestroyComponent(true);
	}

}

void AnoGravityGlass::onFrac(const FVector& HitPoint, const FVector& HitDirection) {
	destr->SetEnableGravity(true);
	broken = true;
}
