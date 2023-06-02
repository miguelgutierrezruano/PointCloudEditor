
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
/// PointCloudEditor window
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
    /// Create a new window
    /// </summary>
    /// <param name="parent">Parent widget</param>
    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

public slots:

    void menuExitTriggered()
    {
        QApplication::quit();
    }

    // View

    // On FieldOfView slider changed
    void fovSliderChanged      (int newValue);

    // On PointSize slider changed
    void pointSizeSliderChanged(int newValue);

    // Reset view to 0, 0, 0
    void resetView();

    // Tools

    // Center point cloud at 0, 0, 0
    void center();

    // Scale point cloud by 2
    void scale2();

    // Reduce point cloud size by half
    void scaleHalf();

    // Rotate point cloud
    void rotate();

    // Change rotation axis from ComboBox
    void changeRotationAxis (int index);

    // Change rotation value from SpinBox
    void changeRotationValue(int value);

    // Open file with explorer 
    void open();

    // Save file
    void save();

    // Save a copy of current file
    void saveCopy();

private:

    void setupOpenGLWidget();
};
