#include "Actor/Coin.h"
#include "Kismet/GameplayStatics.h"


ACoin::ACoin()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACoin::BeginPlay()
{
    Super::BeginPlay();
}

void ACoin::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    SeekTarget(DeltaTime);
}

void ACoin::SeekTarget(float DeltaTime)
{
    if (!ClosestTarget || !ClosestTarget->IsValidLowLevel() || ClosestTarget->IsPendingKillPending())
    {
        if (!TargetActorClass) return;

        TArray<AActor*> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), TargetActorClass, FoundActors);
        
        float ClosestDistanceSq = MAX_FLT;
        ClosestTarget = nullptr;

        for (AActor* Actor : FoundActors)
        {
            if (Actor)
            {
                float CurrentDistanceSq = (Actor->GetActorLocation() - GetActorLocation()).SizeSquared();
                
                if (CurrentDistanceSq < ClosestDistanceSq)
                {
                    ClosestDistanceSq = CurrentDistanceSq;
                    ClosestTarget = Actor;
                }
            }
        }
    }

    if (ClosestTarget)
    {
        FVector Direction = ClosestTarget->GetActorLocation() - GetActorLocation();
        
        Direction.Normalize();

        FVector DeltaLocation = Direction * SeekSpeed * DeltaTime;

        SetActorLocation(GetActorLocation() + DeltaLocation);
    }
}