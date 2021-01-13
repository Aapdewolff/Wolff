workspace "Wolff"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Wolff/vendor/GLFW/include"
IncludeDir["GLAD"] = "Wolff/vendor/GLAD/include"

include "Wolff/vendor/GLFW"
include "Wolff/vendor/GLAD"

project "Wolff"
	location "Wolff"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	pchheader "Wolffpch.h"
	pchsource "Wolff/src/Wolffpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WOLFF_PLATFORM_WINDOWS",
			"WOLFF_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines { "WOLFF_DEBUG", "WOLFF_ENABLE_ASSERTS" }
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "WOLFF_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distribution"
		defines "WOLFF_DISTRIBUTION"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Wolff/vendor/spdlog/include",
		"Wolff/src"
	}

	links
	{
		"Wolff"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WOLFF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WOLFF_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "WOLFF_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distribution"
		defines "WOLFF_DISTRIBUTION"
		buildoptions "/MD"
		optimize "On"