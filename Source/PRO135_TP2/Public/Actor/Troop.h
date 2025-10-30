#pragma once

#include "CoreMinimal.h"
#include "Data/TroopData.h"
#include "GameFramework/Character.h"
#include "Troop.generated.h"

UCLASS()
class PRO135_TP2_API ATroop : public ACharacter
{
	GENERATED_BODY()

public:
	ATroop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Damages = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") 
	float Health = 10.f;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") 
	int MoneyDrop = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") 
	float Speed = 200.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data") 
    UTroopData* TroopDataAsset;

	UFUNCTION(BlueprintCallable, Category = "Movements")
	void SeekTargetActor();

	UFUNCTION(BlueprintCallable, Category = "Movements")
	void RotateTowardsTarget();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements")
	float InterpSpeed = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements")
	float DampingStrength = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements")
	AActor* CurrentTarget;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
