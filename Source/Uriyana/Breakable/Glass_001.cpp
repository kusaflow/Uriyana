// Fill out your copyright notice in the Description page of Project Settings.


#include "Glass_001.h"
#include "Components/BoxComponent.h"
#include "DestructibleComponent.h"
#include "../ThrowBall.h"
 

// Sets default values
AGlass_001::AGlass_001()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UBoxComponent>(TEXT("block"));
	RootComponent = block;

	destr = CreateDefaultSubobject<UDestructibleComponent>(TEXT("destroy"));
	destr->SetupAttachment(RootComponent);

	backMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("backBone"));
	backMesh->SetupAttachment(destr);


	destr->OnComponentHit.AddDynamic(this, &AGlass_001::OnCompHit);

	
}

// Called when the game starts or when spawned
void AGlass_001::BeginPlay()
{
	Super::BeginPlay();
	bisBroken = false;
	
}

// Called every frame
void AGlass_001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bisBroken) {
		if (inRight)
			destr->AddWorldOffset(FVector(0,500 *DeltaTime, 0));
		else 	
			destr->AddWorldOffset(FVector(0, -500 * DeltaTime, 0));

		if (destr->GetComponentLocation().Y > 1000) {
			inRight = false;
		}
		else if (destr->GetComponentLocation().Y < -1000) {
			inRight = true;
		}
	}

}

void AGlass_001 :: OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit) {

	AThrowBall* ball = Cast<AThrowBall>(OtherActor);

	if (ball) {
		destr->ApplyDamage(60000, Hit.Location, Hit.ImpactNormal, 1000);
		if (backMesh)
			backMesh->DestroyComponent();
		
		destr->SetEnableGravity(true);
		bisBroken = true;

	}
}
