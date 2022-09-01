local AcrylicRootDir = '../../../../..'
include (AcrylicRootDir .. "/vendor/premake/premake_customization/solution_items.lua")

workspace "Sandbox"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sandbox"
	kind "SharedLib"
	language "C#"
	dotnetframework "4.7.2"

	targetdir ("Bin")
	objdir ("Bin-Int")

	files 
	{
		"Source/**.cs",
		"Properties/**.cs"
	}

	links
	{
		"Acrylic-ScriptCore"
	}

	filter "configurations:Debug"
		optimize "Off"
		symbols "Default"

	filter "configurations:Release"
		optimize "On"
		symbols "Default"

	filter "configurations:Dist"
		optimize "Full"
		symbols "Off"

group "Acrylic"
	include (AcrylicRootDir .. "/Acrylic-ScriptCore")
group ""