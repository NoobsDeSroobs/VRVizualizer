// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"
#include "GrabberComponent.h"

#define OUT

// Sets default values for this component's properties
UGrabberComponent::UGrabberComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	GrabberID = -1;
	GrabbedActor = nullptr;
}


// Called when the game starts
void UGrabberComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty."));
	///GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);


	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Class %s has no physics handle component."), *GetOwner()->GetName());
	}
}


// Called every frame
void UGrabberComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

}

void UGrabberComponent::GrabOverlappingActor(AActor* VRPointer)
{
	if (PhysicsHandle == nullptr || VRPointer == nullptr ) {
		return;
	}


	TArray<AActor*> OverlappingActors;
	VRPointer->GetOverlappingActors(OUT OverlappingActors);
	///If nothing is overlapping then simply return.

	if (OverlappingActors.Num() == 0) {
		return;
	}
	
	for (AActor* actor : OverlappingActors) {
		if (actor->IsA(AGrabbable::StaticClass())) {
			GrabbedActor = Cast<AGrabbable>(actor);
			GrabberID = GrabbedActor->RegisterGrabber(GetOwner());
			break;
		}
	}

	if (GrabberID == -1)
	{
		GrabbedActor = nullptr;
	}

	if (GrabbedActor != nullptr && GrabberID == 0) {
		GrabbedActor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepWorldTransform);
	}
	//Get pointer: Controller->GetChildActor()
}

void UGrabberComponent::ReleaseOverlappingActor()
{
	if (PhysicsHandle == nullptr || GrabbedActor == nullptr) {
		return;
	}
	GrabbedActor->UnregisterGrabber(GrabberID);
	if (GrabberID == 0)
	{
		GrabbedActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
	GrabberID = -1;
	GrabbedActor = nullptr;
}

TArray<AActor*> UGrabberComponent::GetOverlappingActors(AActor* VRPointer)
{
	TArray<AActor*> OverlappingActors;
	VRPointer->GetOverlappingActors(OUT OverlappingActors);
	return OverlappingActors;
}