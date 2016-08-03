// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#pragma once


#include "GameFramework/Actor.h"
#include <vector>
#include "VTKVolumeActor.generated.h"

UCLASS()
class VIVETEST_API AVTKVolumeActor : public AActor
{
	GENERATED_BODY()

		struct color
	{
		int r, g, b, a;
		color()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 0;
		}
	};
	
public:	
	// Sets default values for this actor's properties
	AVTKVolumeActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "VTK")
		void Render();

	std::vector<AActor*> volume;
	UWorld* World;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voxel")
		TSubclassOf<class AActor> MyItemBlueprint;
	
};
