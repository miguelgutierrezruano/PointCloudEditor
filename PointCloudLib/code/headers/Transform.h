
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "API.h"

namespace mpc
{
	class API Transform
	{
		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale;

	public:

		const glm::vec3& get_position() { return position; }

		void set_position(float x, float y, float z)
		{
			position = glm::vec3(x, y, z);
		}
	};
}
