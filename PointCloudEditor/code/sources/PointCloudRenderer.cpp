
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <glad/glad.h>

#include "PointCloudRenderer.h"

PointCloudRenderer::PointCloudRenderer() :
    view(nullptr)
{

}

void PointCloudRenderer::initialize()
{
    // Glad initialization
    GLenum glad_init = gladLoadGL();

    // Stop program if glad could not load properly
    assert(glad_init != 0);
    std::cout << glGetString(GL_VERSION) << std::endl;

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Enable antialiasing
    //glEnable(GL_MULTISAMPLE);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.2f, 0.2f, 0.2f, 1.f);
    glPointSize(10.f);

    shader = std::make_shared<Shader>("../code/shaders/PointCloudShader.shader");
    setupPointCloud(nullptr);
}

void PointCloudRenderer::resize(int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
}

void PointCloudRenderer::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (view != nullptr)
    {
        std::cout << "Im supposed to be rendering!" << std::endl;
        view->render(shader);
    }
}

void PointCloudRenderer::setupPointCloud(std::shared_ptr<PointCloud> newPointCloud)
{
    pointCloud = newPointCloud;
    view = new PointCloudView(pointCloud);
}
