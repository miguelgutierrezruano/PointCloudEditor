
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>

#include "Camera.h"

namespace mpc
{
	Camera::Camera(float fov, float near, float far)
	{
		fieldOfView = fov;
		nearPlane = near;
		farPlane = far;

		movementSpeed = 0;
		rotationSpeed = 0;
	}

	glm::mat4 Camera::get_view_matrix()
	{
		return glm::lookAtLH(transform.position, transform.position + transform.get_forward(), transform.get_up());
	}

	glm::mat4 Camera::get_projection_matrix(float aspectRatio)
	{
		return glm::perspectiveLH_NO(glm::radians(fieldOfView), aspectRatio, nearPlane, farPlane);
	}
}