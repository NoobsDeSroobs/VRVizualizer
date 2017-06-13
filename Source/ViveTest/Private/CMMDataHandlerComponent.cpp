// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"
#include "CMMDataHandlerComponent.h"
#include "Kismet/KismetStringLibrary.h"


// Sets default values for this component's properties
UCMMDataHandlerComponent::UCMMDataHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCMMDataHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

int UCMMDataHandlerComponent::ReadCMMFile(FString FilePath)
{

	float CMMToUE4Scale = 100;

	FFileHelper::LoadANSITextFileToStrings(*FilePath, nullptr, FileStrings);
	//TADStructs.(FileStrings.Num()-2);
	int numTADs = 0;
	for (int i = 1; i < FileStrings.Num()-1; ++i) {
		FString CurrentTAD = FileStrings[i];
		if(CurrentTAD.StartsWith("<marker")) {		
			//<marker id="0" x="-2.17566"  y="0.471581" z="1.44219" radius="0.208368" r="0.191519" g="0.497664" b="0.622109" chrID="chr10_A" beadID="chr10_A:0-2930000"/>
			FTopologicallyAssociatedDomain CurrentTADStruct;
			//CurrentTAD.FindChar('\'', );
			int CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, 0);
			int CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex+1);
			//UniqueID
			CurrentTADStruct.UniqueID = FCString::Atoi(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex+1, CurrentEndIndex-CurrentStartIndex-1));

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//X
			CurrentTADStruct.Position.X = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1)) * CMMToUE4Scale;

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//Y
			CurrentTADStruct.Position.Y = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1)) * CMMToUE4Scale;

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//Z
			CurrentTADStruct.Position.Z = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1)) * CMMToUE4Scale;

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//Radius/Scale
			CurrentTADStruct.Scale = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1));

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//R
			CurrentTADStruct.Colour.R = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1));

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//G
			CurrentTADStruct.Colour.G = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1));

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//B
			CurrentTADStruct.Colour.B = FCString::Atof(*UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1));
			CurrentTADStruct.Colour.A = 1.0f;

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//TADID
			CurrentTADStruct.ChrID = UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1);

			CurrentStartIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentEndIndex + 1);
			CurrentEndIndex = UKismetStringLibrary::FindSubstring(CurrentTAD, "\"", false, false, CurrentStartIndex + 1);
			//CharID
			CurrentTADStruct.TADID = UKismetStringLibrary::GetSubstring(CurrentTAD, CurrentStartIndex + 1, CurrentEndIndex - CurrentStartIndex - 1);
			if(!TADStructs.Contains(CurrentTADStruct.ChrID)) {
				TADStructs.Emplace(CurrentTADStruct.ChrID, TArray<FTopologicallyAssociatedDomain>());
			}
			TArray<FTopologicallyAssociatedDomain> *ChromoArray = TADStructs.Find(CurrentTADStruct.ChrID);
			ChromoArray->Add(CurrentTADStruct);
			numTADs++;
		}
	}

	return numTADs;
}


TArray<FTopologicallyAssociatedDomain> UCMMDataHandlerComponent::GetStructs(FString ChrID)
{
	return TADStructs[ChrID];
}

TArray<FString> UCMMDataHandlerComponent::GetChromosomeIDs()
{
	TArray<FString> Keys;
	TADStructs.GetKeys(Keys);
	return Keys;
}

FTopologicallyAssociatedDomain UCMMDataHandlerComponent::GetTADData(FVector WorldPosition)
{

	FRotator rot = GetOwner()->GetActorRotation();
	rot = rot.GetInverse();
	FVector RelativePosition = WorldPosition - GetOwner()->GetActorLocation();
	RelativePosition = rot.RotateVector(RelativePosition);
	RelativePosition = RelativePosition / GetOwner()->GetActorScale(); //Maybe change this to actorscale3d
	int32 numChecked = 0;
	for (TPair<FString, TArray<FTopologicallyAssociatedDomain>> TADPair : TADStructs) {
		TArray<FTopologicallyAssociatedDomain> Chromosome = TADPair.Value;
		for (FTopologicallyAssociatedDomain TAD : Chromosome) {
			numChecked++;
			if(abs((TAD.Position-RelativePosition).Size()) <= TAD.Scale*100) {
				return TAD;
			}
		}
	}
	FTopologicallyAssociatedDomain ret = FTopologicallyAssociatedDomain();
	ret.UniqueID = numChecked;
	return ret;
}
