// Fireball Games

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h" 
#include "GameFramework/PlayerController.h"
#include "Grabber.h"

#define OUT

void LogWarning(const FString& Text);
void LogError(const FString& Text);

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void LogWarning(const FString& Text) 
{ 
	UE_LOG(LogTemp, Warning, TEXT("[Grabber] %s"), *Text);
}

void LogError(const FString& Text)
{ 
	UE_LOG(LogTemp, Error, TEXT("[Grabber] %s"), *Text);
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();
	SetupInputComponent();	
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetPlayerReachInfo().Reach);
	}
}

void UGrabber::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle == nullptr)
	{
		LogError(GetOwner()->GetName() + ": Physics handle not found.");
	}
}

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent == nullptr)
	{
		LogError(GetOwner()->GetName() + ": Physics handle not found.");
		return;
	}

	InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::ReleaseGrab);
}

void UGrabber::Grab()
{
	FHitResult Hit = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();

	if (Hit.GetActor())
	{
		PhysicsHandle->GrabComponentAtLocation
		(
			ComponentToGrab,
			NAME_None,
			GetPlayerReachInfo().Reach
		);
	}
}

void UGrabber::ReleaseGrab()
{
	LogWarning("ReleaseGrab function triggered");

	UPrimitiveComponent* GrabbedComponent = PhysicsHandle->GrabbedComponent;
	
	if(GrabbedComponent)
	{
		PhysicsHandle->ReleaseComponent();
		GrabbedComponent->SetWorldRotation(FRotator(.0f));
	}
}

PlayerReachInfo UGrabber::GetPlayerReachInfo() const
{
	PlayerReachInfo NewInfo;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT NewInfo.PlayerViewPointLocation,
        OUT NewInfo.PlayerViewPointRotation
    );

	NewInfo.Reach = NewInfo.PlayerViewPointLocation + NewInfo.PlayerViewPointRotation.Vector() * Reach;
	
    return NewInfo;
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	// Left here just for reference!
	//
	// DrawDebugLine(
	// 	GetWorld(),
	// 	PlayerViewPointLocation,
	// 	LineTraceEnd,
	// 	FColor(0,255,255),
	// 	false,
	// 	0.f,
	// 	0,
	// 	2
	// );

	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	PlayerReachInfo ReachInfo = GetPlayerReachInfo();

	GetWorld()->LineTraceSingleByObjectType(
        OUT Hit,
        ReachInfo.PlayerViewPointLocation,
        ReachInfo.Reach,
        FCollisionObjectQueryParams(ECC_PhysicsBody),
        TraceParams
    );

	// Left here just for reference!!
	// 
	// AActor* HitObject = Hit.GetActor();
	//
	// if (HitObject)
	// {
	// 	LogWarning("HitObject is: " + Hit.GetActor()->GetName());
	// }

	return Hit;
}


