#pragma once

#include "Window.h"

namespace Engine {

	class Application
	{
	public:
		Application();
		void Run();

		Engine::Window* m_Window;
	};

}

