
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include <QtWidgets/QMainWindow>
#include "ui_PointCloudEditor.h"

#include "PointCloudRenderer.h"
#include "OpenGLWidget.h"

using namespace mpc;

using std::shared_ptr;

class PointCloudEditor : public QMainWindow, public Ui::PointCloudEditorClass
{
    Q_OBJECT

private:

    OpenGLWidget* openglWidget;

    PointCloudRenderer renderer;

public:

    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

public slots:

    void menuExitTriggered()
    {
        QApplication::quit();
    }

    void loadPointCloud()
    {
        // Method to load from file
        //renderer.setupPointCloud(pointCloud);
        openglWidget->update();
    }

    void center()
    {
        renderer.centerPointCloud();
        openglWidget->update();
    }

private:

    void setupOpenGLWidget();
};
