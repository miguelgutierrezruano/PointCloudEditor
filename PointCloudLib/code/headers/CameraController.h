
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include "API.h"
#include "Camera.h"

namespace mpc
{
	class API CameraController
	{

	private:

		Camera* currentCamera;

		float speed;

	public:

		CameraController();
		CameraController(Camera* camera);

	public:

		void bindCamera(Camera* camera);
		void unbindCamera();

		// Give parameters based on screen position
		void moveCamera(float delta);
	};
}
