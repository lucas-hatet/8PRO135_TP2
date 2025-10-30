// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TowerData.generated.h"

/**
 * 
 */
UCLASS()
class PRO135_TP2_API UTowerData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* CubeBaseMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float MaxHealth = 1000.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	int ShootEachTick = 60;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float Damages = 5.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Market")
	int Price = 40;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Market")
	float Scope = 2000.f;
};
