
#pragma once

#include "CoreMinimal.h"
#include "Data/TowerData.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class PRO135_TP2_API ATower : public AActor
{

	GENERATED_BODY()
    
public:    
	ATower();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* DetectionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	float DetectionSphereRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TowerBaseMesh; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* BarrelMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	TSubclassOf<ACharacter> TargetCharacterClass;
    
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Targeting")
	ACharacter* CurrentTarget;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int ShootDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float Damages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	int Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	int RoundSetup;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Upgrade();

protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

private:
	ACharacter* FindNearestTarget();
	
	void RotateTowardsTarget();

	int tickCounter = 0;
};
