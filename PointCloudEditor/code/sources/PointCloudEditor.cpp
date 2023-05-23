
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glm/glm.hpp>

#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent),
    camController(&cam), pointCloud("")
{
    ui.setupUi(this);

	camController.print_camera_position();

	float target_fps = 1 / 60.f;

	for (int i = 0; i < 100; i++)
	{
		camController.moveCamera(target_fps);
	}

	pointCloud.center();
	quitAction = ui.actionExit;
}

PointCloudEditor::~PointCloudEditor()
{

}
