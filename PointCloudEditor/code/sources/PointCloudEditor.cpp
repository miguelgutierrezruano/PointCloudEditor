
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glm/glm.hpp>

#include "OpenGLWidget.h"
#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	setupOpenGLWidget();

	pointCloud = std::make_shared<PointCloud>("");
	
	connect(ui.actionExit, &QAction::triggered, this, &PointCloudEditor::menuExitTriggered);
}

PointCloudEditor::~PointCloudEditor()
{
}

void PointCloudEditor::setupOpenGLWidget()
{
	openglWidget = new OpenGLWidget(ui.placeholder, renderer);
	openglWidget->setFixedSize(ui.placeholder->size());
}
