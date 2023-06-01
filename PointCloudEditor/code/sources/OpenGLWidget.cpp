// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent, PointCloudRenderer& renderer) :
    QOpenGLWidget    (parent  ),
    renderer         (renderer),
    mouseLastPosition(0       )
{
    // OpenGL Context initialization
    QSurfaceFormat format;

    format.setDepthBufferSize(24);                     // 24 is more compatible with older GPUs
    format.setVersion(3, 3);                           // OpenGL 3.3
    format.setProfile(QSurfaceFormat::CoreProfile);    // Core Profile

    setFormat(format);

    // Activate mouse tracking on widget
    setMouseTracking(true);
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
    vec2 currentMousePosition = vec2(event->x(), event->y());
    vec2 positionDifference = currentMousePosition - mouseLastPosition;

    mouseLastPosition = currentMousePosition;
    
    // Update camera movement
    if (event->buttons() & Qt::LeftButton)
    {
        renderer.rotatePointCloudY(positionDifference.x);
        renderer.rotateCamera(positionDifference.y);
    }

    update();
}

void OpenGLWidget::wheelEvent(QWheelEvent* event)
{
    int zoomValue = event->angleDelta().y() > 0 ? 1 : -1;
    renderer.zoom(zoomValue);

    update();
}
