
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <glm/glm.hpp>

#include "API.h"

using namespace glm;

namespace mpc
{
	class API Camera
	{
		vec3 position;
		vec3 target;

		double fov;
		bool perspective;

	public:

		const vec3& get_position() { return position; }
		
		void move_camera();
	};
}
