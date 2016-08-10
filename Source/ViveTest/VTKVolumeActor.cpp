// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"

#include "VTKVolumeActor.h"


// Sets default values
AVTKVolumeActor::AVTKVolumeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	volume.reserve(100 * 100 * 100);

}

// Called when the game starts or when spawned
void AVTKVolumeActor::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();

	if (World) {
		int ctr = 0;
		for (int z = -50; z < 50; z+=10) {
			for (int y = -50; y < 50; y += 10) {
				for (int x = -50; x < 50; x += 10) {
					FVector loc = GetActorLocation();
					loc.X += x+5;
					loc.Y += y+5;
					loc.Z += z+5;
					volume.push_back(World->SpawnActor<AActor>(MyItemBlueprint, loc, GetActorRotation()));
					volume[ctr]->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
					volume[ctr]->SetActorScale3D(FVector(0.1, 0.1, 0.1));
					TArray<UStaticMeshComponent*> Components;
					volume[ctr]->GetComponents<UStaticMeshComponent>(Components);
					if (Components[0]->GetName().Compare("Cube") == 0) {
						UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Components[0]->GetMaterial(0), this);
						/*FVector xvec(x, 0, 0);
						FVector yvec(y, 0, 0);
						FVector zvec(z, 0, 0);
						float xCol = FMath::Lerp<float, float>(1, 0, xvec.Size() / 50);
						float yCol = FMath::Lerp<float, float>(1, 0, yvec.Size() / 50);
						float zCol = FMath::Lerp<float, float>(1, 0, zvec.Size() / 50);*/
						if (FMath::Abs(x) < 20 && FMath::Abs(y) < 20 && FMath::Abs(z) < 20) {
							DynamicMaterial->SetVectorParameterValue("Color", FVector(1, 0, 0));
							DynamicMaterial->SetScalarParameterValue("Alpha", 0.8);
						} else {
							DynamicMaterial->SetVectorParameterValue("Color", FVector(0, 1, 0));
							DynamicMaterial->SetScalarParameterValue("Alpha", 0.1);
						}
						Components[0]->SetMaterial(0, DynamicMaterial);
					}

					ctr++;
				}
			}
		}
	}

}

void AVTKVolumeActor::Render()
{



}

// Called every frame
void AVTKVolumeActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

