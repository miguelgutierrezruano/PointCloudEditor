
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glm/glm.hpp>

#include <qfiledialog.h>
#include <qfile.h>
#include <qtextstream.h>

#include "PointCloudLoader.h"
#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
	setupOpenGLWidget();

	rotationAxis = RotationAxis::X;
	rotationValue = 0;
	
	// Connect UI elements with their slot
	connect(     actionExit,    &QAction::triggered, this, &PointCloudEditor::menuExitTriggered     );
	connect(     actionOpen,    &QAction::triggered, this, &PointCloudEditor::open                  );
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

	connect(rotateButton, &QPushButton::clicked, this, &PointCloudEditor::rotate);
	connect(rotationSpinBox, &QSpinBox::valueChanged, this, &PointCloudEditor::changeRotationValue);
	connect(axisComboBox, &QComboBox::currentIndexChanged, this, &PointCloudEditor::changeRotationAxis);
}

PointCloudEditor::~PointCloudEditor()
{
	delete openglWidget;
}

void PointCloudEditor::setupOpenGLWidget()
{
	// Add OpenGLWidget to QtApplication 
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

void PointCloudEditor::rotate()
{
	// Switch between axis
	renderer.rotateAround(rotationValue, rotationAxis);
	openglWidget->update();
}

void PointCloudEditor::changeRotationAxis(int index)
{
	rotationAxis = (RotationAxis)index;
}

void PointCloudEditor::changeRotationValue(int value)
{
	rotationValue = value;
}

void PointCloudEditor::open()
{
	QString filename = QFileDialog::getOpenFileName(this, "Select .ply file", "../resources", "PLY files (*.ply)");

	if (!filename.isEmpty())
	{
		renderer.changePointCloud(filename.toStdString().c_str());
	}

	openglWidget->update();
}

void PointCloudEditor::save()
{
	PointCloudLoader::saveBinaryPLYCloud
	(
		renderer.getPointCloud()->getPath(),
		*renderer.getPointCloud()
	);
}

void PointCloudEditor::saveCopy()
{
	PointCloudLoader::generateBinaryPLYCopy
	(
		renderer.getPointCloud()->getPath(),
		*renderer.getPointCloud()
	);
}