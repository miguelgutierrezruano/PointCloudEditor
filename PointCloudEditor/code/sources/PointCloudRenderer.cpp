
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <glad/glad.h>

#include "Point.h"
#include "PointCloudRenderer.h"

PointCloudRenderer::PointCloudRenderer() :
    view(nullptr), camera(45, 1.f, 400.f)
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
    glEnable(GL_MULTISAMPLE);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.15f, 0.15f, 0.15f, 1.f);

    shader = std::make_shared<Shader>("../code/shaders/PointCloudShader.shader");

    pointCloud = std::make_shared<PointCloud>("../resources/pyramid.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/pyramid-copy.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/boat.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/boat-copy.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/raptor.ply");
    setupPointCloud(pointCloud);

    camera.transform.position = vec3(0, 0, -20);

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
        view->render(shader);
}

void PointCloudRenderer::setupPointCloud(std::shared_ptr<PointCloud> newPointCloud)
{
    pointCloud = newPointCloud;
    view = new PointCloudView(pointCloud);
}

void PointCloudRenderer::centerPointCloud()
{
    if (pointCloud != nullptr)
        updateBuffersCenter(pointCloud->getCenterBox());
}

void PointCloudRenderer::changeFieldOfView(float fov)
{
    camera.set_fov(fov);

    mat4 projection = camera.get_projection_matrix((float)widgetWidth / widgetHeight);

    shader->bind();
    shader->setUniformMat4f("projection", projection);
}

void PointCloudRenderer::changePointSize(float pointSize)
{
    if (pointCloud != nullptr)
        view->setPointSize(pointSize);
}

void PointCloudRenderer::rotatePointCloudX(float value)
{
    if (pointCloud != nullptr)
        pointCloud->transform.rotation.x = value;
}

void PointCloudRenderer::rotatePointCloudY(float value)
{
    if (pointCloud != nullptr)
        pointCloud->transform.rotation.y = value;
}

void PointCloudRenderer::rotatePointCloudZ(float value)
{
    if (pointCloud != nullptr)
        pointCloud->transform.rotation.z = value;
}

void PointCloudRenderer::updateMouseMovement(vec2 positionDiff)
{
    camera.move_camera(positionDiff);

    mat4 view = camera.get_view_matrix();
    shader->bind();
    shader->setUniformMat4f("view", view);
}

void PointCloudRenderer::updateMouseRotation(vec2 positionDiff)
{
    camera.rotate_camera(positionDiff);

    mat4 view = camera.get_view_matrix();
    shader->bind();
    shader->setUniformMat4f("view", view);
}

void PointCloudRenderer::updateBuffersCenter(vec3 center)
{
    for (auto& point : pointCloud->getPoints())
    {
        vec3 pos = point.get_position();
        pos -= center;

        point.set_position(pos);
    }

    // Update GPU buffer
    view->updateGPUBuffer();
}
