
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include "API.h"
#include <vec3.hpp>

namespace mpc
{
	class API Point
	{
		glm::vec3 position;

	public:

		const glm::vec3& get_position() { return position; }

		void set_position(float x, float y, float z)
		{
			position = glm::vec3(x, y, z);
		}
	};
}
