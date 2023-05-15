#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PointCloudEditor.h"

#include "CameraController.h"

using namespace mpc;

class PointCloudEditor : public QMainWindow
{
    Q_OBJECT

private:

    Camera cam;
    CameraController camController;

public:
    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

private:
    Ui::PointCloudEditorClass ui;
};
