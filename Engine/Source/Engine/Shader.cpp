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

		std::string vertexSource;
		std::string fragmentSource;

		vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			vertexFile.open(vertexPath);
			fragmentFile.open(fragmentPath);

			std::stringstream vertexStream, fragmentStream;
			vertexStream << vertexFile.rdbuf();
			fragmentStream << fragmentFile.rdbuf();

			vertexFile.close();
			fragmentFile.close();

			vertexSource = vertexStream.str();
			fragmentSource = fragmentStream.str();
		}
		catch (std::ifstream::failure& error)
		{
			std::cout << "ERROR: FILE NOT SUCCESSFULLY READ: " << error.what() << std::endl;
		}

		const char* c_vertexSource = vertexSource.c_str();
		const char* c_fragmentSource = fragmentSource.c_str();

		// Compile vertex shader
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &c_vertexSource, NULL);
		glCompileShader(vertexShader);
		checkCompileErrors(vertexShader, "VERTEX");

		// Compile fragment shader
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &c_fragmentSource, NULL);
		glCompileShader(fragmentShader);
		checkCompileErrors(fragmentShader, "FRAGMENT");

		// Create the shader program and attach the shaders
		Shader::ID = glCreateProgram();
		glAttachShader(Shader::ID, vertexShader);
		glAttachShader(Shader::ID, fragmentShader);
		glLinkProgram(Shader::ID);
		checkCompileErrors(Shader::ID, "PROGRAM");


		// Delete shaders since they are already attached
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void Shader::use()
	{
		glUseProgram(Shader::ID);
	}

	void Shader::checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR: SHADER COMPILATION FAILED: " << type << "\n" << infoLog << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR: SHADER COMPILATION FAILED: " << type << "\n" << infoLog  << std::endl;
			}
		}
	}

}