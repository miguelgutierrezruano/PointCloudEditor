
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
	
	connect(     actionExit,    &QAction::triggered, this, &PointCloudEditor::menuExitTriggered     );
	connect(     actionSave,    &QAction::triggered, this, &PointCloudEditor::save                  );
	connect( actionSaveCopy,    &QAction::triggered, this, &PointCloudEditor::saveCopy              );

	connect(   actionCenter,    &QAction::triggered, this, &PointCloudEditor::center                );
	connect(actionResetView,    &QAction::triggered, this, &PointCloudEditor::resetView             );
	
	connect(resetViewButton,  &QPushButton::clicked, this, &PointCloudEditor::resetView             );
	connect(   centerButton,  &QPushButton::clicked, this, &PointCloudEditor::center                );
	connect(        scalex2,  &QPushButton::clicked, this, &PointCloudEditor::scale2                );
	connect(       scalex05,  &QPushButton::clicked, this, &PointCloudEditor::scaleHalf             );

	connect(      fovSlider, &QSlider::valueChanged, this, &PointCloudEditor::fovSliderChanged      );
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

void PointCloudEditor::resetView()
{
	renderer.resetView();
	openglWidget->update();
}

void PointCloudEditor::center()
{
	renderer.centerPointCloud();
	openglWidget->update();
}

void PointCloudEditor::scale2()
{
	renderer.scalePointCloud(2.f);
	openglWidget->update();
}

void PointCloudEditor::scaleHalf()
{
	renderer.scalePointCloud(0.5f);
	openglWidget->update();
}

void PointCloudEditor::save()
{
	PointCloudLoader::saveBinaryPLYCloud
	(
		renderer.getPointCloud()->getPath(),
		renderer.getPointCloud()->getPoints()
	);
}

void PointCloudEditor::saveCopy()
{
	PointCloudLoader::generateBinaryPLYCopy
	(
		renderer.getPointCloud()->getPath(),
		renderer.getPointCloud()->getPoints()
	);
}