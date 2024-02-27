#pragma once

#include <string>

namespace Engine {

	class Shader
	{
	public:
		unsigned int ID;
		
		Shader(const char* vertexPath, const char* fragmentPath);
		void use();

	private:
		void checkCompileErrors(unsigned int shader, std::string type);
	};

}
