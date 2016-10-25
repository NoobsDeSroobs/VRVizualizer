// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#pragma once

#include "GameFramework/Actor.h"
#include "Grabbable.generated.h"

UCLASS()
class VIVETEST_API AGrabbable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabbable();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//If it is grabbed we have to ahndle events differently.
	bool IsInitialized;
	//We need a reference to the initial grabbing actor for our calculations.
	AActor* GrabbingActor;
	//The Scalling actor is the secondary grabbing actor we use to interpolate.
	AActor* ScalingActor;
	//The initial Scale is what we need to store to allow for ever growing scales.
	FVector InitialScale;
	//The initial distance is also used to control the scaling as the scale is increased based on the distance difference.
	float InitialDistance;

	UFUNCTION(BlueprintCallable, Category = "Grab")
	void UpdateData();
	int RegisterGrabber(AActor* Actor);
	bool UnregisterGrabber(int ActorID);
	
};
