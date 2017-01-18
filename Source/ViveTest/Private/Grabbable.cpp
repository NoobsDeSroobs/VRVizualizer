// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"
#include "Grabbable.h"


// Sets default values
AGrabbable::AGrabbable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitialDistance = 0;
	GrabbingActor = nullptr;
	ScalingActor = nullptr;
	GrabberPriority = 2;
	
}

// Called when the game starts or when spawned
void AGrabbable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabbable::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//Update scale and rotation
void AGrabbable::UpdateData()
{
	if (GrabbingActor == nullptr || ScalingActor == nullptr)
	{
		return;
	}

	if (!IsInitialized)
	{
		IsInitialized = true;
		InitialScale = GetActorScale();
		InitialDistance = fabs((GrabbingActor->GetActorLocation() - ScalingActor->GetActorLocation()).Size());
	}
	FVector VecBetweenActors = GrabbingActor->GetActorLocation() - ScalingActor->GetActorLocation();
	float NewDistance = fabs(VecBetweenActors.Size());
	float Multiplier = NewDistance / InitialDistance;
	FVector NewScale = InitialScale * Multiplier;
	SetActorScale3D(NewScale);
	//SetActorLocation(ScalingActor->GetActorLocation() + (VecBetweenActors/2));
}

int AGrabbable::RegisterGrabber(AActor* Actor)
{
	int ActorID = -1;
	if (Actor == nullptr)
	{
		return ActorID;
	}

	if (GrabbingActor == nullptr)
	{
		GrabbingActor = Actor;
		ActorID = 0;
		return ActorID;
	}

	if (ScalingActor == nullptr)
	{
		ScalingActor = Actor;
		ActorID = 1;
		return ActorID;
	}

	return ActorID;
}

bool AGrabbable::UnregisterGrabber(int ActorID) {
	switch (ActorID)
	{
	case 0:
		GrabbingActor = nullptr;
		ScalingActor = nullptr;
		IsInitialized = false;
		return true;
		break;
	case 1:
		//GrabbingActor = nullptr;
		ScalingActor = nullptr;
		IsInitialized = false;
		return true;
		break;

	default:
		return false;
		break;
	}
}


void AGrabbable::SetPriority(int32 priority)
{
	GrabberPriority = priority;
}

int AGrabbable::GetPriority()
{
	return GrabberPriority;
}