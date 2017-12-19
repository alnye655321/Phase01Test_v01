// Fill out your copyright notice in the Description page of Project Settings.

#include "EndGameActor.h"


// Sets default values
AEndGameActor::AEndGameActor()
{
	gameOver = false;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EndGameRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot")); // initialize a component
	RootComponent = EndGameRoot; // set the root component --> Collision primitive that defines the transform (location, rotation, scale) of this Actor

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionMesh->SetBoxExtent(FVector(200.f, 200.f, 96.f));
	CollisionMesh->bDynamicObstacle = true;
	CollisionMesh->SetupAttachment(GetRootComponent());
	CollisionMesh->bGenerateOverlapEvents = true;
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AEndGameActor::OnPlayerEnterEndGameBox);


}

// Called when the game starts or when spawned
void AEndGameActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEndGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (gameOver)
	{
		FVector NewLocation = GetActorLocation(); //create new vector equal to current actor location
		NewLocation.Z += (DeltaTime * 100.f); // Z float in FVectors, multiply DeltaTime by 100 for small increments
		SetActorLocation(NewLocation); // set the actor location with an offset of Z - make the actor float
	}

}

void AEndGameActor::OnPlayerEnterEndGameBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString("Overlapper---> ") + OtherActor->GetName());
	gameOver = true;
}

bool AEndGameActor::getGameOver()
{
	if (gameOver)
		return true;
	else
		return false;
}



