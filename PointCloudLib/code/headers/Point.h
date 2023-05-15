
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once
#pragma warning( disable : 4251 )

#include <glm/glm.hpp>

#include "API.h"


namespace mpc
{
	class API Point
	{
		glm::vec3 position;
		glm::vec4 color;

	public:

		const glm::vec3& get_position() { return position; }

		void set_position(float x, float y, float z)
		{
			position = glm::vec3(x, y, z);
		}
	};
}
