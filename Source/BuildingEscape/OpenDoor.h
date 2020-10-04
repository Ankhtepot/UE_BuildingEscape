// Fireball Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;

private:
	UPROPERTY(EditAnywhere)
		float MassToOpenDoor = 50.f;
	UPROPERTY(EditAnywhere)
		float OpenAngle = 90.f;
	UPROPERTY(EditAnywhere)
		float OpenCloseAngleTolerance = 1.f;
	UPROPERTY(EditAnywhere)
		float SpeedInterpTo = 2.f;
	UPROPERTY(EditAnywhere)
		float CloseDoorSpeedMultiplier = 2.f;
	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 2.f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;
	UPROPERTY(EditAnywhere)
		AActor* ActorThatOpen;

	float InitialDoorRotation;
	float LastTimeOpened = 0.f;
};
