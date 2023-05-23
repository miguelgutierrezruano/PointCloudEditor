
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PointCloudEditor.h"

#include "CameraController.h"
#include "PointCloud.h"

using namespace mpc;

class PointCloudEditor : public QMainWindow
{
    Q_OBJECT

private:

    Camera cam;
    CameraController camController;

    PointCloud pointCloud;

public:

    QAction* quitAction;

public:

    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

private:

    Ui::PointCloudEditorClass ui;
};
