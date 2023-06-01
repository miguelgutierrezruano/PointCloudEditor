
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

/// <summary>
/// PointCloudEditor implementation of QtWindow
/// </summary>
class PointCloudEditor : public QMainWindow, public Ui::PointCloudEditorClass
{
    Q_OBJECT

private:

    enum RotationAxis
    {
        X, Y, Z
    };

    OpenGLWidget* openglWidget;
    PointCloudRenderer renderer;

    RotationAxis rotationAxis;
    int rotationValue;

public:

    /// <summary>
    /// Create new PointCloudEditor window
    /// </summary>
    /// <param name="parent">Parent widget</param>
    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

public slots:

    // On menu exit triggered quit application
    void menuExitTriggered()
    {
        QApplication::quit();
    }

    // View

    // Method called on FieldOfView slider changed
    void fovSliderChanged      (int newValue);

    // Method called on PointSize slider changed
    void pointSizeSliderChanged(int newValue);

    // Reset camera
    void resetView();

    // Tools

    // Center point cloud
    void center();

    // Increase point cloud size by 2
    void scale2();

    // Decrease point cloud size by half
    void scaleHalf();

    // Rotate point cloud around selected axis selected degrees
    void rotate();

    // OnRotationAxis ComboBox changed
    void changeRotationAxis (int index);

    // OnRotationValue Spinbox changed
    void changeRotationValue(int value);

    // Save point cloud file
    void save();

    // Save copy of point cloud file in the same folder
    void saveCopy();

private:

    void setupOpenGLWidget();
};
