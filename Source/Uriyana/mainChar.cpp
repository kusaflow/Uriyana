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
#include "gameInstance/kusaGameInstance.h"
#include "Components/BoxComponent.h"

// Sets default values
AmainChar::AmainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(RootComponent);

	FollowCamera->SetRelativeLocation(FVector(10,0,70));

	gun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("gun"));
	gun->SetupAttachment(FollowCamera);

	fireLoc = CreateDefaultSubobject<UBoxComponent>(TEXT("fireLoc"));
	fireLoc->SetupAttachment(FollowCamera);

	gun->SetRelativeLocation(FVector(70, 10, -30));
	gun->SetRelativeRotation(FRotator(0, -90, 0));
	gun->SetRelativeScale3D(FVector(0.4));


	fireLoc->SetRelativeLocation(FVector(90, 10, -30));
	fireLoc->SetRelativeRotation(FRotator(3, 0, 0));
	fireLoc->SetRelativeScale3D(FVector(0.5));

}

// Called when the game starts or when spawned
void AmainChar::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = 600;

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->Health = 1000;


	

	
}

// Called every frame
void AmainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForword();

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->playerXpos = GetRootComponent()->GetComponentLocation().X;
	FRotator camR = FollowCamera->GetRelativeRotation();
	RootComponent->GetChildComponent(1)->SetRelativeRotation(FRotator(0, camR.Yaw-90, 0));
	//RootComponent->SetRelativeRotation(FRotator(camR.Pitch, camR.Yaw, camR.Roll));

	gameInst->Health -= 15 * DeltaTime;

	if (gameInst->Health <0) {
		UGameplayStatics::OpenLevel(this, FName("gameOver"), true);
	}
}

// Called to bind functionality to input
void AmainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("shoot", IE_Pressed, this, &AmainChar::shoot);
	PlayerInputComponent->BindAxis("xAxis", this, &AmainChar::CameraYaw_z);
	PlayerInputComponent->BindAxis("yAxis", this, &AmainChar::CameraPitch_y);

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

	//FVector Dir, loc;
	//playCtrl->DeprojectMousePositionToWorld(loc, Dir);

	//RootComponent->GetChildComponent(1)->SetRelativeRotation(FRotator(Dir.Y, Dir.Z, Dir.X));

	//UE_LOG(LogTemp, Warning, TEXT("x:%f, y:%f, z:%f"), &loc.X, &loc.Y, &loc.Z);

	//FVector FinalVec = FVector(loc.X + (Dir.X*100), loc.Y + (Dir.Y*100), loc.Z + (Dir.Z*100));

	FVector loc = fireLoc->GetComponentLocation();

	AThrowBall* actor;
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	if (ball) {
		UWorld* world = GetWorld();
		if (world) {
			actor = world->SpawnActor<AThrowBall>(ball, loc, FRotator(0), spawnPara);
			
			FVector forceToBall = fireLoc->GetForwardVector();
			//4300
			forceToBall.X *= 3500;
			forceToBall.Y *= 3500;
			forceToBall.Z *= 3500;
			actor->getMesh()->AddImpulse(forceToBall, NAME_None, true);
		}
	}





}

void AmainChar::CameraYaw_z(float val) {
	FRotator newR = FollowCamera->GetRelativeRotation();
	newR.Yaw = FMath::Clamp(newR.Yaw + val, -60.0f, 60.0f);

	FollowCamera->SetRelativeRotation(newR);

}

void AmainChar::CameraPitch_y(float val) {
	FRotator newR = FollowCamera->GetRelativeRotation();
	newR.Pitch = FMath::Clamp(newR.Pitch + val, -30.0f, 30.0f);

	FollowCamera->SetRelativeRotation(newR);

}






