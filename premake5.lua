workspace "Acrylic"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Acrylic/vendor/GLFW/include"
IncludeDir["Glad"] = "Acrylic/vendor/Glad/include"
IncludeDir["ImGui"] = "Acrylic/vendor/imgui"

include "Acrylic/vendor/GLFW"
include "Acrylic/vendor/Glad"
include "Acrylic/vendor/imgui"

project "Acrylic"
	location "Acrylic"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "acpch.h"
	pchsource "Acrylic/src/acpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"AC_PLATFORM_WINDOWS",
			"AC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "AC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AC_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Acrylic/vendor/spdlog/include",
		"Acrylic/src"
	}

	links
	{
		"Acrylic"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"AC_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} ../bin/" .. outputdir .. "/Acrylic/Acrylic.dll ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AC_DIST"
		runtime "Release"
		optimize "On"