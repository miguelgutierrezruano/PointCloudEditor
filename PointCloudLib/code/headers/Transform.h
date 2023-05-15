
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once
#pragma warning( disable : 4251 )

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "API.h"

namespace mpc
{
	class API Transform
	{

	public:

		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale;
	};
}
