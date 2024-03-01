#include "Window.h"
#include "Application.h"

namespace Engine {

	Window::Window(int width, int height, const std::string title)
	{
		Window::width = width;
		Window::height = height;
		Window::title = title;
	}

	void Window::Initialize()
	{
		if (!glfwInit())
			return;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(Window::width, Window::height, Window::title.c_str(), NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_Window);
	}

	void Window::OnUpdate()
	{
		// Swap buffers and poll events
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

}