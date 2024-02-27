#include "Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }

        glfwTerminate();
	}

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}