
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include "CameraController.h"

using namespace mpc;

int main()
{
	Camera cam;

	cam.say_hello();
	CameraController cameraController(&cam);

	float target_fps = 1 / 60.f;

	while (true)
	{
		cameraController.moveCamera(target_fps);
	}

	return 0;
}