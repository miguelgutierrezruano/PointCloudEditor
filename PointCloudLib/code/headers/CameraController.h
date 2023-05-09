
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

		void print_camera_position();

		void set_camera_position(float x, float y, float z);

		// Give parameters based on screen position
		void moveCamera(float delta);
	};
}
