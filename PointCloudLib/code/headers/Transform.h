
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once
#pragma warning( disable : 4251 )

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "API.h"

using namespace glm;

namespace mpc
{
	class API Transform
	{

	public:

		vec3 position;
		vec3 rotation;
		vec3 scale;

	public:

		Transform();
		Transform(const vec3& startPosition, const vec3& startRotation, const vec3 startScale);

		const vec3 get_forward();
		const vec3 get_right();
		const vec3 get_up();

		const mat4 get_matrix();

		static vec3 get_position_from_matrix(mat4 transformationMatrix);
		static vec3 get_rotation_from_matrix(mat4 transformationMatrix);
		static vec3 get_scale_from_matrix   (mat4 transformationMatrix);
	};
}
