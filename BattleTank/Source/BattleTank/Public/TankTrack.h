// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Maximum driving force in neutons.
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 107200.f;

private:
	UTankTrack();
	void ApplySidewaysForce();
	virtual void BeginPlay() override;
	void UTankTrack::DriveTrack();

	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;
};
