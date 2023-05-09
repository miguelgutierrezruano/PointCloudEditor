
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

	cameraController.print_camera_position();
	cameraController.set_camera_position(0, 0, 0);
	cameraController.print_camera_position();

	float target_fps = 1 / 60.f;

	for (int i = 0; i < 100; i++)
	{
		cameraController.moveCamera(target_fps);
	}

	return 0;
}