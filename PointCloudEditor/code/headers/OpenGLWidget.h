
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <iostream>

#include <qevent.h>

#include <glad/glad.h>
#include <qopenglwidget.h>

#include "PointCloudRenderer.h"

using namespace gli;

class OpenGLWidget : public QOpenGLWidget
{
private:

    PointCloudRenderer& renderer;
    vec2 mouseLastPosition;

public:

    // OpenGL Context Creation
    OpenGLWidget(QWidget* parent, PointCloudRenderer& renderer);

    // Method used by Qt before doing any resizeGL or paintGL
    void initializeGL() override
    {
        renderer.initialize();
    }

    // Render on OpenGL Widget
    void paintGL() override
    {
        renderer.render();
    }

    // Resize widget
    void resizeGL(int width, int height) override
    {
        renderer.resize(width, height);
    }

protected:

    // For left and middle clicks
    void mouseMoveEvent(QMouseEvent* event) override;
};
