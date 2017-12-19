// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"

#include "EndGameActor.generated.h"

UCLASS()
class PHASE01TEST_V01_API AEndGameActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEndGameActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// root component for everything else to be attached to
	// A SceneComponent has a transform and supports attachment, but has no rendering or collision capabilities. Useful as a 'dummy' component in the hierarchy to offset others
	UPROPERTY(EditAnywhere)
		USceneComponent* EndGameRoot;

	UPROPERTY(EditAnywhere)
		UBoxComponent* CollisionMesh;

	UPROPERTY(EditAnywhere)
		bool gameOver;

	// called when player enters the box
	UFUNCTION()
		void OnPlayerEnterEndGameBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "EndGameTriggerBox")
		bool getGameOver();


};
