
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glm/glm.hpp>

#include "PointCloudLoader.h"
#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
	setupOpenGLWidget();
	
	connect(actionExit, &QAction::triggered, this, &PointCloudEditor::menuExitTriggered);
	connect(actionSave, &QAction::triggered, this, &PointCloudEditor::saveAs);
	connect(centerButton, &QPushButton::clicked, this, &PointCloudEditor::center);

	connect(fovSlider, &QSlider::valueChanged, this, &PointCloudEditor::fovSliderChanged);
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

void PointCloudEditor::center()
{
	renderer.centerPointCloud();
	openglWidget->update();
}

void PointCloudEditor::fovSliderChanged(int newValue)
{
	renderer.changeFieldOfView((float)newValue);
	openglWidget->update();
}

void PointCloudEditor::pointSizeSliderChanged(int newValue)
{
	renderer.changePointSize((float)newValue);
	openglWidget->update();
}

void PointCloudEditor::rotationXSliderChanged(int newValue)
{
	renderer.rotateCamera((float)newValue);
	openglWidget->update();
}

void PointCloudEditor::rotationYSliderChanged(int newValue)
{
	renderer.rotatePointCloudY((float)newValue);
	openglWidget->update();
}

void PointCloudEditor::saveAs()
{
	PointCloudLoader::generateBinaryPLYCopy
	(
		renderer.getPointCloud()->getPath(),
		renderer.getPointCloud()->getPoints()
	);
}