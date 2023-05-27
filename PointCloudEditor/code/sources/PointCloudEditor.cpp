
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
	connect(centerButton, &QPushButton::clicked, this, &PointCloudEditor::center);

	connect(pointSizeSlider, &QSlider::valueChanged, this, &PointCloudEditor::pointSizeSliderChanged);
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

void PointCloudEditor::pointSizeSliderChanged(int newValue)
{
	renderer.changePointSize((float)newValue);
	openglWidget->update();
}

void PointCloudEditor::center()
{
	renderer.centerPointCloud();
	openglWidget->update();
}
