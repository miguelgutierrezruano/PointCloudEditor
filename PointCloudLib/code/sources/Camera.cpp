
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

		movementSpeed = 0.2f;
		rotationSpeed = 0;
	}

	glm::mat4 Camera::get_view_matrix()
	{
		return glm::lookAtLH(transform.position, vec3(0), transform.get_up());
	}

	glm::mat4 Camera::get_projection_matrix(float aspectRatio)
	{
		return glm::perspectiveLH_NO(glm::radians(fieldOfView), aspectRatio, nearPlane, farPlane);
	}

	void Camera::set_fov(float fov)
	{
		fieldOfView = fov;
	}

	void Camera::move_camera(glm::vec2 positionDifference)
	{
		// Update x axis
		transform.position = transform.position + transform.get_right() * positionDifference.x * movementSpeed;

		// Update y axis
		transform.position = transform.position + transform.get_up() * positionDifference.y * movementSpeed;
	}
}