// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max upward speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 20; // Sensible default

	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegrees = -5; // Sensible default

	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegrees = 35; // Sensible default
};
