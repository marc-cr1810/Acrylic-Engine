project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Acylic/vendor/spdlog/include",
		"%{wks.location}/Acylic/src",
		"%{wks.location}/Acylic/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Acylic"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "AC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AC_DIST"
		runtime "Release"
		optimize "on"
