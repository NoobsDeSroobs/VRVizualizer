// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#pragma once

#include "Components/ActorComponent.h"
#include "ViveController.h"
#include "Grabbable.h"

#include "GrabberComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIVETEST_API UGrabberComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabberComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	UFUNCTION(BlueprintCallable, Category = "Grab")
		virtual void GrabOverlappingActor(AActor* VRPointer);
	UFUNCTION(BlueprintCallable, Category = "Grab")
		virtual void ReleaseOverlappingActor();
	UFUNCTION(BlueprintCallable, Category = "Overlap")
		virtual TArray <AActor*> GetOverlappingActors(AActor* VRPointer);

private:
	AGrabbable* GrabbedActor = nullptr;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	int GrabberID;
};
