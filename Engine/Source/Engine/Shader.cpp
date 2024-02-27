#include "Shader.h"

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Engine {

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		// Parse shader files
		std::ifstream vertexFile;
		std::ifstream fragmentFile;

		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);

		std::stringstream vertexStream, fragmentStream;
		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();

		vertexFile.close();
		fragmentFile.close();

		const char* vertexSource = vertexStream.str().c_str();
		const char* fragmentSource = fragmentStream.str().c_str();

		// Compile vertex shader
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		// Compile fragment shader
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		// Create the shader program and attach the shaders
		Shader::ID = glCreateProgram();
		glAttachShader(Shader::ID, vertexShader);
		glAttachShader(Shader::ID, fragmentShader);
		glLinkProgram(Shader::ID);

		// Delete shaders since they are already attached
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void Shader::use()
	{
		glUseProgram(Shader::ID);
	}

}