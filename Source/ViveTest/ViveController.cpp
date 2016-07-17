// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"
#include "ViveController.h"


// Sets default values
AViveController::AViveController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AViveController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AViveController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

