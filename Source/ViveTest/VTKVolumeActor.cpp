// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"
#include "VTKVolumeActor.h"


// Sets default values
AVTKVolumeActor::AVTKVolumeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVTKVolumeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVTKVolumeActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

