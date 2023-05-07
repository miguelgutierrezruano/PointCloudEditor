
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

	void CameraController::moveCamera(float delta)
	{
		if (currentCamera == nullptr)
		{
			std::cout << "Controlled camera doesn't exist!" << std::endl;
			return;
		}

		Transform cameraTransform = currentCamera->get_transform();
		vec3 pos = cameraTransform.get_position();

		cameraTransform.set_position(pos.x, pos.y, pos.z + speed * delta);

		pos = cameraTransform.get_position();

		std::cout << "Camera position: " <<  pos.x << ", " << pos.y << ", " << pos.z << std::endl;
	}
}