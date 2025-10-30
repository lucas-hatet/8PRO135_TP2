#include "Actor/Tower.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

ATower::ATower()
{
    PrimaryActorTick.bCanEverTick = true;
    
    RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    RootComponent = RootScene;

    DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
    DetectionSphere->SetupAttachment(RootComponent); 
    
    TowerBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    TowerBaseMesh->SetupAttachment(RootScene); 
    BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
    BarrelMesh->SetupAttachment(TowerBaseMesh);
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    DetectionSphere->SetSphereRadius(DetectionSphereRadius);
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    CurrentTarget = FindNearestTarget();
    if (CurrentTarget)
    {
        RotateTowardsTarget();
        tickCounter++;
        if (tickCounter >= ShootDelay)
        {
            Shoot();
            tickCounter = 0;
        }
    }
}

ACharacter* ATower::FindNearestTarget()
{
    if (!TargetCharacterClass)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "cANT FindNearestTarget");
        return nullptr;
    }
        

    TArray<AActor*> OverlappingActors;
    DetectionSphere->GetOverlappingActors(OverlappingActors, TargetCharacterClass);

    ACharacter* NearestTarget = nullptr;
    float MinDistanceSq = FLT_MAX;
    FVector TurretLocation = GetActorLocation();

    for (AActor* Actor : OverlappingActors)
    {
        ACharacter* Character = Cast<ACharacter>(Actor);
        if (Character)
        {
            float DistanceSq = FVector::DistSquared(TurretLocation, Character->GetActorLocation());
            
            if (DistanceSq < MinDistanceSq)
            {
                MinDistanceSq = DistanceSq;
                NearestTarget = Character;
            }
        }
    }

    return NearestTarget;
}

void ATower::RotateTowardsTarget()
{
    if (!CurrentTarget || !BarrelMesh) return;

    FVector TargetLocation = CurrentTarget->GetActorLocation();
    FVector TurretBaseLocation = BarrelMesh->GetComponentLocation(); 
    FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(TurretBaseLocation, TargetLocation);
    
    BarrelMesh->SetRelativeRotation(FRotator(TargetRotation.Pitch, TargetRotation.Yaw, 0.0f));
}

void ATower::Upgrade()
{
    Level++;
    MaxHealth += 200;
    Health = MaxHealth;
    Damages = FMath::TruncToInt(Damages * 1.5);
    Price *= 3;
}
