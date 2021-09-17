include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Acrylic"
	architecture "x86_64"
	startproject "Acrylic-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Acrylic/vendor/Box2D"
	include "Acrylic/vendor/GLFW"
	include "Acrylic/vendor/Glad"
	include "Acrylic/vendor/imgui"
	include "Acrylic/vendor/yaml-cpp"
group ""

include "Acrylic"
include "Sandbox"
include "Acrylic-Editor"
