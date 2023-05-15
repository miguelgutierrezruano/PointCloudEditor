
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

		friend class CameraController;

	private:

		Transform transform;

		float fov;
		float near;
		float far;

	public:

		Camera();
	};
}
