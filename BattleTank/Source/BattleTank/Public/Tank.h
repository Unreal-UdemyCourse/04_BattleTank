// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
		// Sets default values for this pawn's properties
		ATank();

		virtual float TakeDamage
		(
			float DamageAmount,
			struct FDamageEvent const & DamageEvent,
			class AController * EventInstigator,
			AActor * DamageCauser
		) override;

		//Returns current health as percentage of starting health between 0 and 1
		UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealthPercent() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth = StartingHealth;
};