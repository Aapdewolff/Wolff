workspace "Wolff"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wolff"
	location "Wolff"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WOLFF_PLATFORM_WINDOWS",
			"WOLFF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WOLFF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WOLFF_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "WOLFF_DISTRIBUTION"
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
		symbols "On"

	filter "configurations:Release"
		defines "WOLFF_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "WOLFF_DISTRIBUTION"
		optimize "On"