#include "Actor/Spawner.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

