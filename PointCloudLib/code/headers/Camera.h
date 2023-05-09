
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <glm/glm.hpp>

#include "API.h"
#include "Transform.h"

using namespace glm;

namespace mpc
{
	class API Camera
	{
		Transform transform;
		//vec3 target;

		double fov;
		bool perspective;

	public:

		Transform& get_transform() { return transform; }

		void say_hello();
	};
}
