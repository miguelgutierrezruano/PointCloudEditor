
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>

#include "Camera.h"

namespace mpc
{
	Camera::Camera() 
		: 
		transform(),
		fov(70.f), near(0.1f), far(100.f)
	{

	}
}