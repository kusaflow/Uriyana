// Fill out your copyright notice in the Description page of Project Settings.


#include "mainChar.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "ThrowBall.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AmainChar::AmainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(RootComponent);

	FollowCamera->SetRelativeLocation(FVector(0,0,70));

}

// Called when the game starts or when spawned
void AmainChar::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = 600;
	
}

// Called every frame
void AmainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForword();

}

// Called to bind functionality to input
void AmainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("shoot", IE_Pressed, this, &AmainChar::shoot);
}


void AmainChar :: MoveForword() {
	if (Controller != nullptr) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, 1);
	}
}


void AmainChar::shoot() {
	
	APlayerController* playCtrl = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FVector Dir, loc;
	playCtrl->DeprojectMousePositionToWorld(loc, Dir);


	FVector FinalVec = FVector(loc.X + (Dir.X*100), loc.Y + (Dir.Y*100), loc.Z + (Dir.Z*100));

	AThrowBall* actor;
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	if (ball) {
		UWorld* world = GetWorld();
		if (world) {
			actor = world->SpawnActor<AThrowBall>(ball, FinalVec, FRotator(0), spawnPara);
			actor->SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
			
			FVector forceToBall = Dir;
			forceToBall.X *= 5000;
			forceToBall.Y *= 5000;
			forceToBall.Z *= 5000;
			actor->getMesh()->AddImpulse(forceToBall, NAME_None, true);
		}
	}





}