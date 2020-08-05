// Fill out your copyright notice in the Description page of Project Settings.


#include "noGravityGlass.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../ThrowBall.h"
#include "../gameInstance/kusaGameInstance.h"
#include "../mainChar.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AnoGravityGlass::AnoGravityGlass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<UBoxComponent>(TEXT("root"));
	RootComponent = root;

	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	destr->SetupAttachment(RootComponent);

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	block->SetupAttachment(destr);

	root->SetCollisionProfileName("NoCollision");

	block->OnComponentBeginOverlap.AddDynamic(this, &AnoGravityGlass::OnOverlapBegin);

	block->SetGenerateOverlapEvents(true);

	broken = false;
	destr->SetEnableGravity(false);

	//destr->OnComponentFracture.AddDynamic(this, &AnoGravityGlass :: onFrac);

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
	
	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());

	//hit damage
	if (gameInst->GunIndex == 1) {
		if (gameInst->Theme == 1) {
			if (gameInst->CurrentGunStamina < 500) {
				basedamage = 5000000.0;
				impulseRadius = 10000.0;
				impulse = 5000.0;
			}
			else if (gameInst->CurrentGunStamina < 1000) {
				basedamage = 5000000.0;
				impulseRadius = 10000.0;
				impulse = 30000.0;
			}
			else if (gameInst->CurrentGunStamina <= 1100) {
				basedamage = 9000000.0;
				impulseRadius = 10000.0;
				impulse = 50000.0;
			}
		}
		else if (gameInst->Theme == 2) {
			if (gameInst->CurrentGunStamina < 500) {
				basedamage = 5000000.0;
				impulseRadius = 10000.0;
				impulse = 10000.0;
			}
			else if (gameInst->CurrentGunStamina < 1000) {
				basedamage = 5000000.0;
				impulseRadius = 10000.0;
				impulse = 90000.0;
			}
			else if (gameInst->CurrentGunStamina <= 1100) {
				basedamage = 9000000.0;
				impulseRadius = 10000.0;
				impulse = 500000.0;
			}
		}
	}

	//---------------------------------
	

	if (mainCh) {
		if (!broken) {

			if (gameInst) {
				gameInst->Health -= 100;
				gameInst->bGotHit = true;
				broken = true;
				if (soundFX)
					UGameplayStatics::SpawnSoundAtLocation(this, soundFX, RootComponent->GetComponentLocation());
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
		//destr->SetEnableGravity(true);
		broken = true;
		destr->DestroyComponent(true);
	}

}

void AnoGravityGlass::onFrac(const FVector& HitPoint, const FVector& HitDirection) {
	destr->SetEnableGravity(true);
	broken = true;
	if (soundFX)
		UGameplayStatics::SpawnSoundAtLocation(this, soundFX, RootComponent->GetComponentLocation());
}
