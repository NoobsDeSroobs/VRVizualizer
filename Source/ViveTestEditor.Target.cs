// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ViveTestEditorTarget : TargetRules
{
	public ViveTestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
        ExtraModuleNames.Add("ViveTest");
    }

	//
	// TargetRules interface.
	//
    
}
