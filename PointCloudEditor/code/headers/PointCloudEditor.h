
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

    void center();
    void fovSliderChanged      (int newValue);
    void pointSizeSliderChanged(int newValue);
    void rotationXSliderChanged(int newValue);
    void rotationYSliderChanged(int newValue);

    void saveAs();

private:

    void setupOpenGLWidget();
};
