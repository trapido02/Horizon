#include "ResizeWindowEvent.h"

#include "GLFW/glfw3.h"

#include <iostream>

namespace Engine {

	ResizeWindowEvent::ResizeWindowEvent(int width, int height)
	{
		std::cout << "Got window resize event." << std::endl;
		glViewport(0, 0, width, height);
	}

}