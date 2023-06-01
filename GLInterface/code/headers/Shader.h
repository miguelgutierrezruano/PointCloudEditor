
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

	/// <summary>
	/// OpenGL Shader handler
	/// </summary>
	class Shader
	{

	private:

		std::string path;
		unsigned int id;
		
		std::unordered_map< std::string, int > uniformLocationCache;

	public:

		/// <summary>
		/// Create and compile a shader on GPU
		/// </summary>
		/// <param name="shaderPath">Path of the shader file</param>
		Shader(const std::string& shaderPath);
	   ~Shader();

	public:

		/// <summary>
		/// Bind shader
		/// </summary>
		void bind() const;

		/// <summary>
		/// Unbind shader
		/// </summary>
		void unbind() const;

		// Set int uniform variable
		void setUniform1i(const std::string& name, int value);
		// Set float uniform variable
		void setUniform1f(const std::string& name, float value);
		// Set vec3 uniform variable
		void setUniform3f(const std::string& name, glm::vec3 vec);
		// Set vec4 uniform variable
		void setUniform4f(const std::string& name, glm::vec4 vec);
		// Set mat4 uniform variable
		void setUniformMat4f(const std::string& name, glm::mat4& mat);

	private:

		int getUniformLocation(const std::string& name);

		ShaderSource parseShader(const std::string& path);
		unsigned int compileShader(unsigned int type, const std::string& source);
		unsigned int createShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
	};
}
