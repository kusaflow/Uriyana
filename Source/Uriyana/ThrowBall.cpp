// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowBall.h"
#include "Components/StaticMeshComponent.h"
#include "gameInstance/kusaGameInstance.h"

// Sets default values
AThrowBall::AThrowBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ball"));
	RootComponent = ball;
}

// Called when the game starts or when spawned
void AThrowBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThrowBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	float playerPosX = gameInst->playerXpos;

	if (timer < 12000)
	if (ball->GetComponentLocation().X < playerPosX) {
		if (ball)
			Destroy();
	}

}

UStaticMeshComponent* AThrowBall :: getMesh() {
	if (ball)
		return ball;

	return nullptr;
}