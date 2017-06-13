// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CMMDataHandlerComponent.generated.h"


USTRUCT(BlueprintType)
struct VIVETEST_API FTopologicallyAssociatedDomain
{
	GENERATED_BODY()
		//<marker id="0" x="-2.17566"  y="0.471581" z="1.44219" radius="0.208368" r="0.191519" g="0.497664" b="0.622109" chrID="chr10_A" beadID="chr10_A:0-2930000"/>
	UPROPERTY(BlueprintReadWrite, Category = "TAD")
	int32 UniqueID;
	UPROPERTY(BlueprintReadWrite, Category = "TAD")
	FVector Position;
	UPROPERTY(BlueprintReadWrite, Category = "TAD")
	float Scale;
	UPROPERTY(BlueprintReadWrite, Category = "TAD")
	FLinearColor Colour;
	UPROPERTY(BlueprintReadWrite, Category = "TAD")
	FString TADID;
	UPROPERTY(BlueprintReadWrite, Category = "TAD")
	FString ChrID;

/*
		int32 GetUniqueID()
		{
			return UniqueID;
		}
		FVector GetPosition() {
			return Position;
		}
		 
		float GetScale() {
			return Scale;
		}
		
		FColor GetColour() {
			return Colour;
		}
		 
		FString GetTADID() {
			return TADID;
		}
		 
		FString GetChrID() {
			return ChrID;
		}*/
		 



	//Constructor
	FTopologicallyAssociatedDomain() {
		UniqueID = -1;
		Scale = 0;
		TADID = "EmptyTAD";
		ChrID = "EmptyTAD";
	}
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIVETEST_API UCMMDataHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCMMDataHandlerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	TArray<FString> FileStrings;
	TMap<FString, TArray<FTopologicallyAssociatedDomain>> TADStructs;

public:	
	UFUNCTION(BlueprintCallable, Category = "FileHandling")
	int ReadCMMFile(FString FilePath);

	UFUNCTION(BlueprintCallable, Category = "DataHandling")
		TArray<FTopologicallyAssociatedDomain> GetStructs(FString ChrID);

	UFUNCTION(BlueprintCallable, Category = "DataHandling")
		TArray<FString> GetChromosomeIDs();

};

