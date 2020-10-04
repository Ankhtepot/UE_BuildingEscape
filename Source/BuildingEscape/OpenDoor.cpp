// Fireball Games

#include "Components/PrimitiveComponent.h"
#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialDoorRotation = GetOwner()->GetActorRotation().Yaw;

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("[Open Door]: Object \"%s\" is missing PressurePlate actor."), *GetOwner()->GetName());
	}

	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PressurePlate)
	{
		OpenDoor(DeltaTime);
		CloseDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(float DeltaTime) 
{
	float targetRotationYaw = InitialDoorRotation + OpenAngle - OpenCloseAngleTolerance;
	// if (PressurePlate->IsOverlappingActor(ActorThatOpen) && GetOwner()->GetActorRotation().Yaw < targetRotationYaw)
	if (TotalMassOfActors() > MassToOpenDoor && GetOwner()->GetActorRotation().Yaw < targetRotationYaw)
	{

		float CurrentRotationYaw = GetOwner()->GetActorRotation().Yaw;
		if (CurrentRotationYaw < targetRotationYaw - OpenCloseAngleTolerance)
		{
			LastTimeOpenned = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("[Open Door]: LastTimeOpenned: %f."), LastTimeOpenned);
		}

		//float newYaw = FMath::Lerp(CurrentRot ationYaw, InitialDoorRotation + TargetYaw, DeltaTime * 1.f);
		float newYaw = FMath::FInterpTo(CurrentRotationYaw, InitialDoorRotation + OpenAngle, DeltaTime, SpeedInterpTo);

		GetOwner()->SetActorRotation(FRotator(0.f, newYaw, 0.f));
	}	
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	// if (GetWorld()->GetTimeSeconds() - LastTimeOpenned > DoorCloseDelay
	// 	&& !PressurePlate->IsOverlappingActor(ActorThatOpen) 
	// 	&& GetOwner()->GetActorRotation().Yaw > InitialDoorRotation + OpenCloseAngleTollerance)
	if (GetWorld()->GetTimeSeconds() - LastTimeOpenned > DoorCloseDelay
		&& TotalMassOfActors() < MassToOpenDoor
		&& GetOwner()->GetActorRotation().Yaw > InitialDoorRotation + OpenCloseAngleTolerance)
	{
		LastTimeOpenned = 0.f;
		float CurrentRotationYaw = GetOwner()->GetActorRotation().Yaw;
		//float newYaw = FMath::Lerp(CurrentRot ationYaw, InitialDoorRotation + TargetYaw, DeltaTime * 1.f);
		float newYaw = FMath::FInterpTo(CurrentRotationYaw, InitialDoorRotation, DeltaTime, SpeedInterpTo * CloseDoorSpeedMultiplier);

		GetOwner()->SetActorRotation(FRotator(0.f, newYaw, 0.f));
	}
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	
	return  TotalMass;
}




