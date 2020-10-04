// Fireball Games

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

struct FPlayerReachInfo
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FVector Reach;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		float Reach = 300.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	void Grab();
	void ReleaseGrab();
	void FindPhysicsHandle();
	void SetupInputComponent();
	// Return the First Actor within reach with physics body.
	FHitResult GetFirstPhysicsBodyInReach() const;
	FPlayerReachInfo GetPlayerReachInfo() const;
};
