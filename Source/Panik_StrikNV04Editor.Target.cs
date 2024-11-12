

using UnrealBuildTool;
using System.Collections.Generic;

public class Panik_StrikNV04EditorTarget : TargetRules
{
	public Panik_StrikNV04EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Panik_StrikNV04" } );
	}
}
