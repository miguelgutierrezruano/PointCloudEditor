#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PointCloudEditor.h"

class PointCloudEditor : public QMainWindow
{
    Q_OBJECT

public:
    PointCloudEditor(QWidget *parent = nullptr);
    ~PointCloudEditor();

private:
    Ui::PointCloudEditorClass ui;
};
