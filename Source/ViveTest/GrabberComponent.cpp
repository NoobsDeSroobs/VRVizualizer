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

	if (GrabbedActor && false) {
		//Get parent location
		FVector OwnerTranslation = GetOwner()->GetActorLocation();
		FRotator OwnerRotation = GetOwner()->GetActorRotation();
		GrabbedActor->SetActorLocation(OwnerTranslation + OffsetTranslation);
		GrabbedActor->SetActorRotation(OwnerRotation + OffsetRotation);


		//Set transform with offset to make the grabbed actor move with the parent component.
	}
}

void UGrabberComponent::GrabOverlappingActor()
{
	if (PhysicsHandle == nullptr) {
		return;
	}
	TArray<AActor*> OverlappingActors;
	TSubclassOf<AActor> Filter;

	TArray<UChildActorComponent*> comps;

	GetOwner()->GetComponents(comps);
	UChildActorComponent* Controller = nullptr;
	for (auto ChildActorComponent: comps) {
		if (ChildActorComponent->GetChildActorName().ToString().StartsWith("ViveController")) {
			Controller = ChildActorComponent;
		}
	}

	
	Controller->GetChildActor()->GetOverlappingActors(OUT OverlappingActors);
	///If nothing is overlapping then simply return.

	if (OverlappingActors.Num() == 0) {
		return;
	}

	GrabbedActor = OverlappingActors[0];
	GrabbedActor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepWorldTransform);
	FTransform OwnerTransform = GetOwner()->GetActorTransform();
	FTransform OtherActorTransform = GrabbedActor->GetActorTransform();

	UPrimitiveComponent* ComponentToGrab = GrabbedActor->GetRootPrimitiveComponent();
	FVector PointerLocation = Controller->GetChildActor()->GetActorLocation();
	PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, PointerLocation, true);
	OffsetTranslation = FVector(OtherActorTransform.GetLocation() - OwnerTransform.GetLocation());
	OffsetRotation = FRotator(OtherActorTransform.GetRotation() - OwnerTransform.GetRotation());
}

void UGrabberComponent::ReleaseOverlappingActor()
{
	if (PhysicsHandle == nullptr) {
		return;
	}
	GrabbedActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	PhysicsHandle->ReleaseComponent();
	GrabbedActor = nullptr;
}