// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_CPP_API UPlayerStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatsComponent();

protected:

	//UPROPERTY(Replicated)
		float Hunger;
	//UPROPERTY(Replicated)
		float Thirst;
	UPROPERTY(EditAnywhere,Category="S|PlayerStats")
	float HungerDecrementValue;
	UPROPERTY(EditAnywhere,Category="S|PlayerStats")
	float ThirstDecrementValue;
	FTimerHandle TimerHandle;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	void HandleHungerAndThhirst();

	UFUNCTION(Server,Reliable, WithValidation)
	void ServerLowerHunger(float Value);
	
	bool ServerLowerHunger_Validate(float Value);
	void ServerLowerHunger_Implementation(float Value);

	UFUNCTION(Server,Reliable, WithValidation)
	void ServerLowerThirst(float Value);
	
	bool ServerLowerThirst_Validate(float Value);
	void ServerLowerThirst_Implementation(float Value);
public:	
	void LowerHunger(float value);
	void LowerThirst(float value);
	float GetHunger();
	float GetThirst();
		
};
