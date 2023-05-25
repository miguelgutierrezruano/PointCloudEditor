
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

	// Initialize OpenGL
	//renderer.initialize();

	pointCloud = std::make_shared<PointCloud>("");
	//renderer.setPointCloud(pointCloud);

	//renderer.render();
	quitAction = ui.actionExit;
}

PointCloudEditor::~PointCloudEditor()
{
}

void PointCloudEditor::setupOpenGLWidget()
{
	/*openglWidget = new OpenGLWidget(ui.widget, renderer);
	openglWidget->setFixedSize(ui.widget->size());*/
}
