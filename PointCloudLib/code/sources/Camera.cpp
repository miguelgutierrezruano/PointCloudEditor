
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
		rotationSpeed = 0.2f;
		zoomSpeed = 10.f;
	}

	glm::mat4 Camera::get_view_matrix()
	{
		return glm::lookAtLH(transform.position, transform.position + transform.get_forward(), transform.get_up());
	}

	glm::mat4 Camera::get_projection_matrix(float aspectRatio)
	{
		return glm::perspectiveLH_NO(glm::radians(fieldOfView), aspectRatio, nearPlane, farPlane);
	}

	void Camera::set_fov(float fov)
	{
		fieldOfView = fov;
	}

	void Camera::zoom(int value)
	{
		transform.position = transform.position + transform.get_forward() * zoomSpeed * (float)value;
	}

	void Camera::move_camera(glm::vec2 positionDifference)
	{
		// Update x axis
		transform.position = transform.position + transform.get_right() * positionDifference.x * movementSpeed;

		// Update y axis
		transform.position = transform.position + transform.get_up() * positionDifference.y * movementSpeed;
	}

	void Camera::rotate_camera(glm::vec2 positionDifference)
	{
		// Update x axis
		transform.rotation = vec3
		(
			transform.rotation.x + positionDifference.y * rotationSpeed,
			transform.rotation.y,
			transform.rotation.z
		);

		// Update y axis
		transform.rotation = vec3
		(
			transform.rotation.x,
			transform.rotation.y + positionDifference.x * rotationSpeed,
			transform.rotation.z
		);
	}
}