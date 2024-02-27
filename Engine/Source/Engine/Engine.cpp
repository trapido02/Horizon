#include "Engine.h"

#include <GLFW/glfw3.h>

#include <iostream>

namespace Engine {

	void CreateWindow()
	{
        GLFWwindow* window;

        if (!glfwInit())
            return;

        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }

        glfwTerminate();
	}

}