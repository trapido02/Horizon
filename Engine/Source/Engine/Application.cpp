#include "Application.h"

#include <iostream>

namespace Engine {

	Application::Application()
	{
		m_Window = new Window(800, 600, "Title");
		m_Window->Initialize();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		};
		// Will eventually run functions to update window etc.
	}

}