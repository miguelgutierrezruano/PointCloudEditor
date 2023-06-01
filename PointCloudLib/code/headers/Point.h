
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once
#pragma warning( disable : 4251 )

#include <glm/glm.hpp>

#include "API.h"


namespace mpc
{
	/// <summary>
	/// Point definition
	/// </summary>
	class API Point
	{
		glm::vec3 position;
		glm::vec3 color;

	public:

		Point()
		{
			position = glm::vec3(0);
			color    = glm::vec3(0);
		}

		Point(glm::vec3 position, glm::vec3 color)
		{
			this->position = position;
			this->color = color;
		}

		const glm::vec3& get_position() { return position; }
		const glm::vec3& get_color   () { return    color; }

		void set_position(float x, float y, float z)
		{
			position = glm::vec3(x, y, z);
		}

		void set_position(glm::vec3 position)
		{
			this->position = position;
		}
	};
}
