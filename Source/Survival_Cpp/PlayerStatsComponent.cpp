// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsComponent.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UPlayerStatsComponent::UPlayerStatsComponent()
{
	Hunger=100.0f;
	Thirst=100.0f;
	HungerDecrementValue=0.3;
	ThirstDecrementValue=0.5;

}



// Called when the game starts
void UPlayerStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&UPlayerStatsComponent::HandleHungerAndThhirst,3.0f,true);
	
}

void UPlayerStatsComponent::HandleHungerAndThhirst()
{
	
	LowerHunger(HungerDecrementValue);
	LowerThirst(ThirstDecrementValue);
}

void UPlayerStatsComponent::ServerLowerHunger_Implementation(float Value)
{
	if(GetOwnerRole()==ROLE_Authority)
	{
		LowerHunger((Value));
	}
}

bool UPlayerStatsComponent::ServerLowerHunger_Validate(float Value)
{
	return true;
}



void UPlayerStatsComponent::ServerLowerThirst_Implementation(float Value)
{
	if(GetOwnerRole()==ROLE_Authority)
	{
		LowerThirst((Value));
	}
}

bool UPlayerStatsComponent::ServerLowerThirst_Validate(float Value)
{
	return true;
}



void UPlayerStatsComponent::LowerHunger(float value)
{
	if(GetOwnerRole()<ROLE_Authority)
	{
		ServerLowerHunger(value);
	}else
	{
		Hunger-=value;
	}
}

void UPlayerStatsComponent::LowerThirst(float value)
{
	if(GetOwnerRole()<ROLE_Authority)
	{
		ServerLowerThirst(value);
	}else
	{
		Thirst-=value;
	}
}

float UPlayerStatsComponent::GetHunger()
{
	return  Hunger;
}

float UPlayerStatsComponent::GetThirst()
{
	return Thirst;
}



