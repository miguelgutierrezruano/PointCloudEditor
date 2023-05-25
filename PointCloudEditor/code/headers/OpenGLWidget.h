
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

//#include <qopenglwidget.h>
#include "Renderer.hpp"

using namespace gli;

//class OpenGLWidget : public QOpenGLWidget
//{
//private:
//
//    Renderer& renderer;
//
//public:
//
//    // OpenGL Context Creation
//    OpenGLWidget(QWidget* parent, Renderer& renderer);
//
//    // Method used by Qt before doing any resizeGL or paintGL
//    void initializeGL() override
//    {
//        renderer.initialize();
//    }
//
//    // Render on OpenGL Widget
//    void paintGL() override
//    {
//        renderer.render();
//    }
//
//    // Resize widget
//    void resizeGL(int width, int height) override
//    {
//        renderer.resize(width, height);
//    }
//
//};
