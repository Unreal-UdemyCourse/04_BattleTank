// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


// Begin Play
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Tick executed each frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Move towards the player
	MoveToActor(
		Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()),
		AcceptanceRadius,
		true,
		true,
		false,
		0,
		true
		);

	// Aim towards the player
	Cast<ATank>(GetPawn())->AimAt(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());

	// TODO Fire if ready
	Cast<ATank>(GetPawn())->Fire();
}
