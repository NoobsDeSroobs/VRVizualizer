// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class ViveTest : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    }

    public ViveTest(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //LoadVTK(Target);

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");
        // if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
        // {
        //		if (UEBuildConfiguration.bCompileSteamOSS == true)
        //		{
        //			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        //		}
        // }
    }

    public bool LoadVTK(TargetInfo Target)
    {
        bool isLibrarySupported = false;

        //if ((Target.Platform == UnrealTargetPlatform.Win64))
        //{
        //    isLibrarySupported = true;
            
        //    string LibrariesPath = Path.Combine(ThirdPartyPath, "VTK", "lib");
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkalglib-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkChartsCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonColor-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonComputationalGeometry-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonDataModel-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonExecutionModel-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonMath-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonMisc-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonSystem-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkCommonTransforms-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkDICOMParser-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkDomainsChemistry-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkDomainsChemistryOpenGL2-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkexoIIc-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkexpat-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersAMR-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersExtraction-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersFlowPaths-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersGeneral-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersGeneric-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersGeometry-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersHybrid-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersHyperTree-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersImaging-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersModeling-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersParallel-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersParallelImaging-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersProgrammable-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersSelection-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersSMP-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersSources-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersStatistics-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersTexture-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkFiltersVerdict-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkfreetype-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkGeovisCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkglew-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkhdf5-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkhdf5_hl-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingColor-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingFourier-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingGeneral-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingHybrid-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingMath-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingMorphological-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingSources-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingStatistics-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkImagingStencil-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkInfovisCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkInfovisLayout-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkInteractionImage-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkInteractionStyle-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkInteractionWidgets-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOAMR-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOEnSight-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOExodus-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOExport-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOGeometry-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOImage-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOImport-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOInfovis-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOLegacy-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOLSDyna-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOMINC-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOMovie-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIONetCDF-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOParallel-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOParallelXML-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOPLY-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOSQL-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOVideo-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOXML-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkIOXMLParser-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkjpeg-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkjsoncpp-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtklibxml2-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkmetaio-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkNetCDF-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkNetCDF_cxx-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkoggtheora-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkParallelCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkpng-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingAnnotation-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingContext2D-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingContextOpenGL2-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingFreeType-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingImage-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingLabel-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingLOD-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingOpenGL2-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingVolume-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkRenderingVolumeOpenGL2-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtksqlite-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtksys-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtktiff-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkverdict-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkViewsContext2D-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkViewsCore-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkViewsInfovis-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkzlib-7.0.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "vtkxdmf3.lib"));
        //    PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "XdmfCore.lib"));


        //    string OpenGLPath = Path.Combine(ThirdPartyPath, "glew", "lib", "Release", "x64");
        //    PublicAdditionalLibraries.Add(Path.Combine(OpenGLPath, "glew32.lib"));


        //}

        //if (isLibrarySupported)
        //{
        //    // Include path
        //    PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "VTK", "include", "vtk-7.0"));
        //    PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "glm"));
        //    PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "glew", "include"));
        //}

        //Definitions.Add(string.Format("UsingVTK={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }



}

