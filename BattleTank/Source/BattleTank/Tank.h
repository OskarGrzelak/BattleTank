// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);
	// Called every frame
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel * BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret * TurretToSet);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent * TankAimingComponent = nullptr;

public:	
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 8000.f;

	
	
};
