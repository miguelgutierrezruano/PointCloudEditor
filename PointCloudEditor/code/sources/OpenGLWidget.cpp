// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent, PointCloudRenderer& renderer) :
    QOpenGLWidget    (parent  ),
    renderer         (renderer),
    mouseLastPosition(0)
{
    // OpenGL Context initialization
    QSurfaceFormat format;

    format.setDepthBufferSize(24);                     // 24 is more compatible with older GPUs
    format.setVersion(3, 3);                           // OpenGL 3.3
    format.setProfile(QSurfaceFormat::CoreProfile);    // Core Profile

    setFormat(format);

    setMouseTracking(true);
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
    vec2 currentMousePosition = vec2(event->x(), event->y());
    vec2 positionDifference = currentMousePosition - mouseLastPosition;

    mouseLastPosition = currentMousePosition;
    
    // Update camera movement
    if (event->buttons() & Qt::LeftButton)
        renderer.updateMouseMovement(positionDifference);
    // Update camera movement
    else if (event->buttons() & Qt::MiddleButton)
        renderer.updateMouseMovement(positionDifference);
    // Update camera rotation
    else if (event->buttons() & Qt::RightButton)
        renderer.updateMouseRotation(positionDifference);

    update();
}
