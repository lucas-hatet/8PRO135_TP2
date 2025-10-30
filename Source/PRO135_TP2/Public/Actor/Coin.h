#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class PRO135_TP2_API ACoin : public AActor
{
	GENERATED_BODY()
    
public: 
	ACoin();

protected:
	virtual void BeginPlay() override;

public: 
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek")
	TSubclassOf<AActor> TargetActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seek")
	float SeekSpeed = 50.0f; 

private:
	void SeekTarget(float DeltaTime);

	UPROPERTY()
	AActor* ClosestTarget = nullptr; 
};