#pragma once

#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace Engine {

	class Window
	{
	public:
		int width;
		int height;
		std::string title;

		Window(int width, int height, const std::string title);

		void Initialize();

		void OnUpdate();

		GLFWwindow* m_Window;

	};

}

