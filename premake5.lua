workspace "WhatsThisEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "WhatsThisEngine"
	location "WhatsThisEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "WhatsThisEngine/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{wks.location}/WhatsThisEngine/vendor/spdlog/include",
		"WhatsThisEngine/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

	    defines
		{
			"WTE_PLATFORM_WINDOWS",
			"WTE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WTE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WTE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WTE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{wks.location}/WhatsThisEngine/vendor/spdlog/include",
		"WhatsThisEngine/src",
	}

	links
	{
		"WhatsThisEngine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"WTE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WTE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WTE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WTE_DIST"
		optimize "On"