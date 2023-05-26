
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <glad/glad.h>

#include "PointCloudRenderer.h"

PointCloudRenderer::PointCloudRenderer() :
    view(nullptr), camera(45, 1.f, 150.f)
{
    widgetWidth  = 1920;
    widgetHeight = 1080;
}

PointCloudRenderer::~PointCloudRenderer()
{
    delete view;
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
    glPointSize(2.f);

    shader = std::make_shared<Shader>("../code/shaders/PointCloudShader.shader");

    pointCloud = std::make_shared<PointCloud>("../resources/pyramid.ply");
    setupPointCloud(pointCloud);

    camera.transform.position = vec3(10, 40, -70);
    camera.transform.rotation = vec3(20, 0, 0);

    pointCloud->transform.rotation = vec3(-90, 0, 0);

    mat4 projection = camera.get_projection_matrix((float)widgetWidth / widgetHeight);
    mat4 view = camera.get_view_matrix();

    shader->bind();
    shader->setUniformMat4f("projection", projection);
    shader->setUniformMat4f("view", view);
}

void PointCloudRenderer::resize(int newWidth, int newHeight)
{
    widgetWidth  =  newWidth;
    widgetHeight = newHeight;

    glViewport(0, 0, newWidth, newHeight);

    mat4 projection = camera.get_projection_matrix((float)widgetWidth / widgetHeight);

    shader->bind();
    shader->setUniformMat4f("projection", projection);
}

void PointCloudRenderer::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (view != nullptr)
    {
        std::cout << "Render!" << std::endl;
        view->render(shader);
    }
}

void PointCloudRenderer::setupPointCloud(std::shared_ptr<PointCloud> newPointCloud)
{
    pointCloud = newPointCloud;
    view = new PointCloudView(pointCloud);
}
