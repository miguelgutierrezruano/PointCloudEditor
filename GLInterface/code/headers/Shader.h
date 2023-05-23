
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace gli
{
	struct ShaderSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

	class Shader
	{

	private:

		std::string path;
		unsigned int id;
		
		std::unordered_map< std::string, int > uniformLocationCache;

	public:

		Shader(const std::string& shaderPath);
	   ~Shader();

	public:

		void bind() const;
		void unbind() const;

		// Set uniforms
		void setUniform1i(const std::string& name, int value);
		void setUniform1f(const std::string& name, float value);
		void setUniform3f(const std::string& name, glm::vec3 vec);
		void setUniform4f(const std::string& name, glm::vec4 vec);
		void setUniformMat4f(const std::string& name, glm::mat4& mat);

	private:

		int getUniformLocation(const std::string& name);

		ShaderSource parseShader(const std::string& path);
		unsigned int compileShader(unsigned int type, const std::string& source);
		unsigned int createShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
	};
}
