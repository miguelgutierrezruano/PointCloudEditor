
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glm/glm.hpp>

#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
	setupOpenGLWidget();
	
	connect(actionExit, &QAction::triggered, this, &PointCloudEditor::menuExitTriggered);
	connect(actionLoad, &QAction::triggered, this, &PointCloudEditor::loadPointCloud);
}

PointCloudEditor::~PointCloudEditor()
{
	delete openglWidget;
}

void PointCloudEditor::setupOpenGLWidget()
{
	openglWidget = new OpenGLWidget(placeholder, renderer);
	openglWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	placeholder->layout()->addWidget(openglWidget);
}
