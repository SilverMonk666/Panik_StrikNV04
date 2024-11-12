

using UnrealBuildTool;
using System.Collections.Generic;

public class Panik_StrikNV04Target : TargetRules
{
	public Panik_StrikNV04Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Panik_StrikNV04" } );
	}
}
