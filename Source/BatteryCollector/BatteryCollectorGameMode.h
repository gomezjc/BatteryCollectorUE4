// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override; 
	
	UFUNCTION(BlueprintPure,Category="Power")
	float GetPowerToWin() const;

	UFUNCTION(BlueprintPure,Category="Power")
	EBatteryPlayState GetCurrentState() const;

	void SetCurrentState(EBatteryPlayState NewState);
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="Power")
	float DecayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta=(BlueprintProtected="true"))
	float PowerToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;

private:

	EBatteryPlayState CurrentState;
};



