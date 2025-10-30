#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TroopData.generated.h"



UCLASS()
class PRO135_TP2_API UTroopData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* CubeBaseMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	bool IsAllied = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float MaxHealth = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float MovementSpeed = 300.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float Damages = 5.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Market")
	int MinMoneyDrop = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Market")
	int MaxMoneyDrop = 5;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	bool IsFlying = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	bool IsShooting = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targets")
	TSubclassOf<AActor> FirstTypeTarget;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Targets")
	TSubclassOf<AActor> SecondTypeTarget;
    	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Targets")
	TSubclassOf<AActor> ThirdTypeTarget;
};
