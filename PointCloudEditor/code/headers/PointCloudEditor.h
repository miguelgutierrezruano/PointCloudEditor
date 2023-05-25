
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include <QtWidgets/QMainWindow>
#include "ui_PointCloudEditor.h"

#include "PointCloudRenderer.h"

using namespace mpc;

using std::shared_ptr;

class OpenGLWidget;

class PointCloudEditor : public QMainWindow
{
    Q_OBJECT

private:

    OpenGLWidget* openglWidget;
    PointCloudRenderer renderer;

    // Here because SerializeSystem may use it too
    shared_ptr< PointCloud > pointCloud;

public:

    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

public slots:

    void menuExitTriggered()
    {
        QApplication::quit();
    }

private:

    void setupOpenGLWidget();

private:

    Ui::PointCloudEditorClass ui;
};
