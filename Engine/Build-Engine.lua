project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
	staticruntime "off"

	files { "Source/**.h", "Source/**.cpp", "vendor/glad/src/glad.c" }

	includedirs
	{
		"Source",
		"vendor/glfw/include",
		"vendor/glad/include"
	}

	libdirs
	{
		"vendor/glfw/lib-vc2022"
	}

	links
	{
		"glfw3.lib",
		"opengl32.lib"
	}

	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		defines { }

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