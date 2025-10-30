// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/TroopData.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class PRO135_TP2_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	ACharacter* EnemyClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	UTroopData* DataAsset;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
