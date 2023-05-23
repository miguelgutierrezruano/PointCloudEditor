
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include <QtWidgets/QMainWindow>
#include "ui_PointCloudEditor.h"

#include "CameraController.h"
#include "PointCloudRenderer.h"

using namespace mpc;

using std::shared_ptr;

class PointCloudEditor : public QMainWindow
{
    Q_OBJECT

private:

    Camera cam;
    CameraController camController;

    // Here because SerializeSystem may use it too
    shared_ptr< PointCloud > pointCloud;
    PointCloudRenderer renderer;

public:

    QAction* quitAction;

public:

    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

private:

    Ui::PointCloudEditorClass ui;
};
