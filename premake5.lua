workspace "Newton"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Newton/vendor/GLFW/include"

include "Newton/vendor/GLFW"

project "Newton"
	location "Newton"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "newtonpch.h"
	pchsource "Newton/src/newtonpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NEWTON_PLATFORM_WINDOWS",
			"NEWTON_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NEWTON_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NEWTON_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NEWTON_DIST"
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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Newton/vendor/spdlog/include",
		"Newton/src"
	}

	links
	{
		"Newton"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NEWTON_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NEWTON_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NEWTON_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NEWTON_DIST"
		optimize "On"