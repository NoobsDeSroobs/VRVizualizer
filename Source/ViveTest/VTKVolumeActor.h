// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#pragma once


#include "GameFramework/Actor.h"
#include "VTKVolumeActor.generated.h"

UCLASS()
class VIVETEST_API AVTKVolumeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVTKVolumeActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
