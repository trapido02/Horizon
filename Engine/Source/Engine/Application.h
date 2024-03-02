#pragma once

#include "Window.h"

namespace Engine {

	class Application
	{
	public:
		Application();
		void Run();
	private:
		bool m_Running = true;
		Engine::Window* m_Window;
	};

}

