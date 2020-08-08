workspace "DataStructures"
	architecture "x64"
	startproject "DataStructures"

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

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.archutecture}"

project "DataStructures"
	location "DataStructures"
	kind "ConsoleApp"
	language "C++"
	cppdialect"C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DataStructures/ThirdParty",
		"DataStructures/src"
	}

	links
	{
		
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "_CONTAINER_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "_CONTAINER_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "_CONTAINER_DIST"
		runtime "Release"
		optimize "on"
