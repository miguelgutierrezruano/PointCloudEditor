
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

	public:

		Transform transform;

	private:

		float fieldOfView;
		float nearPlane;
		float farPlane;

	public:

		Camera(float fov, float near, float far);

	public:

		// Inverse camera transform
		glm::mat4 get_view_matrix();

		// Get projection matrix given by values
		glm::mat4 get_projection_matrix(float aspectRatio);

		void set_fov(float fov);
	};
}
