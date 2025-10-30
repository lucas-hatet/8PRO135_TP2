// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PRO135_TP2_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int Round = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	bool Break = true;

	UPROPERTY(BlueprintReadOnly, Category = "Market")
	int BreakDuration = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	int StartingMoney = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	int StartingTroops = 0;
	
};
