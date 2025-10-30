#include "Actor/Troop.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

ATroop::ATroop()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATroop::BeginPlay()
{
	Super::BeginPlay();
}

void ATroop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATroop::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATroop::SeekTargetActor()
{
	if (!CurrentTarget || !GetCharacterMovement())
	{
		return;
	}

	if (GetCharacterMovement()->MovementMode != MOVE_Flying)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}

	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation = CurrentTarget->GetActorLocation();
    
	FVector IdealDirection = (TargetLocation - CurrentLocation);
	IdealDirection.Normalize();

	FVector CurrentForward = GetActorForwardVector();
	FVector NewDirection = FMath::VInterpTo(CurrentForward, IdealDirection, GetWorld()->GetDeltaSeconds(), InterpSpeed);
	NewDirection.Normalize();

	AddMovementInput(NewDirection, Speed * GetWorld()->GetDeltaSeconds()); 

	FRotator TargetRotation = NewDirection.Rotation();
    
	FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), InterpSpeed);
	SetActorRotation(NewRotation);
}

void ATroop::RotateTowardsTarget()
{
	if (!CurrentTarget) return;

	FVector ActorLocation = GetActorLocation();
	FVector TargetLocation = CurrentTarget->GetActorLocation();
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(ActorLocation, TargetLocation);
    
	SetActorRelativeRotation(FRotator(TargetRotation.Pitch, TargetRotation.Yaw, 0.0f));
}