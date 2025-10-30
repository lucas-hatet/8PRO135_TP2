#pragma once

#include "Engine/DataTable.h"
#include "AssaultDataStruct.generated.h"



USTRUCT(BlueprintType)
struct FAssaultDataStruct : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Troops")
	int EnemyOneHerdOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Troops")
	int EnemyOneHerdTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Troops")
	int EnemyOneHerdThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Troops")
	int EnemyTwoHerdOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Troops")
	int EnemyTwoHerdTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Troops")
	int EnemyThreeHerdThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float TimeBetweenSpawns;
	
};