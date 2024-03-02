project "Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
	staticruntime "off"

	files { "Source/**.h", "Source/**.cpp" }

	includedirs
	{
		"Source",

		-- Include Engine
		"../Engine/Source",

		-- Include GLFW (This is only a temporary solution until we can switch to cmake where we can choose to add the dependency implicitly)
		"../Engine/Vendor/glfw/include"
	}

	libdirs
	{
		-- Temporary
		"../Engine/Vendor/glfw/lib-vc2022"
	}

	links
	{
		"Engine",

		-- Temporary
		"glfw3.lib",
		"opengl32.lib"
	}

	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		defines { "WINDOWS" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"