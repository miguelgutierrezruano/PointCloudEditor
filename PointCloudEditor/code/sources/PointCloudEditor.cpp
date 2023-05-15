#include <glm/glm.hpp>

#include "PointCloudEditor.h"

PointCloudEditor::PointCloudEditor(QWidget *parent)
    : QMainWindow(parent),
    camController(&cam)
{
    ui.setupUi(this);
}

PointCloudEditor::~PointCloudEditor()
{

}
