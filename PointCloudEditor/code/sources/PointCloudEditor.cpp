#include <glm/glm.hpp>

#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent),
    camController(&cam)
{
    ui.setupUi(this);

    cam.say_hello();

	camController.print_camera_position();
	camController.set_camera_position(0, 0, 0);
	camController.print_camera_position();

	float target_fps = 1 / 60.f;

	for (int i = 0; i < 100; i++)
	{
		camController.moveCamera(target_fps);
	}

	float advanced = cam.get_transform().get_position().z;
	std::string text = "I advanced";
	ui.label->setText(text.c_str());
}

PointCloudEditor::~PointCloudEditor()
{

}
