
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>

#include "CameraController.h"

namespace mpc
{
	CameraController::CameraController()
		: currentCamera(nullptr), speed(10)
	{

	}

	CameraController::CameraController(Camera* camera)
		: currentCamera(camera), speed(10)
	{

	}

	void CameraController::bindCamera(Camera* camera)
	{
		currentCamera = camera;
	}

	void CameraController::unbindCamera()
	{
		currentCamera = nullptr;
	}

	void CameraController::print_camera_position()
	{
		vec3 pos = currentCamera->transform.position;

		std::cout << "Camera position: " << pos.x << ", " << pos.y << ", " << pos.z << std::endl;
	}

	void CameraController::set_camera_position(float x, float y, float z)
	{
		currentCamera->transform.position = vec3(x, y, z);
	}

	void CameraController::moveCamera(float delta)
	{
		if (currentCamera == nullptr)
		{
			std::cout << "Controlled camera doesn't exist!" << std::endl;
			return;
		}

		vec3 pos = currentCamera->transform.position;

		currentCamera->transform.position = vec3(pos.x, pos.y, pos.z + speed * delta);

		print_camera_position();
	}
}