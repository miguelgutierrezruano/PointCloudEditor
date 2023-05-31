
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <glad/glad.h>

#include <glm/gtx/rotate_vector.hpp>

#include "Point.h"
#include "PointCloudTransformation.h"
#include "PointCloudRenderer.h"

PointCloudRenderer::PointCloudRenderer() :
    view(nullptr), camera(45, 1.f, 150.f)
{
    widgetWidth  = 1920;
    widgetHeight = 1080;

    cameraRadius = 20.f;
    cameraAngle = 0;

    cameraMovementSpeed = 0.5f;
    modelRotationSpeed = 0.6f;
    zoomSpeed = 0.3f;

    cameraAngleLimits = vec2(  85,  -85);
    zoomLimits        = vec2(0.5f, 70.f);

    cameraInitialPosition = vec3(0, 0, -20);
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

    glClearColor(0.15f, 0.15f, 0.15f, 1.f);

    shader = std::make_shared<Shader>("../code/shaders/PointCloudShader.shader");

    //pointCloud = std::make_shared<PointCloud>("../resources/pyramid.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/pyramid-copy.ply");
    pointCloud = std::make_shared<PointCloud>("../resources/boat.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/boat-copy.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/nebula.ply");
    setupPointCloud(pointCloud);

    camera.transform.position = cameraInitialPosition;

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

#pragma region View methods

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

void PointCloudRenderer::resetView()
{
    cameraAngle = 0;
    rotateCamera(0);

    pointCloud->transform.rotation = vec3(0);
    updateViewMatrix();
}

#pragma endregion

#pragma region Editor methods

void PointCloudRenderer::centerPointCloud()
{
    updateCPUBufferCenter(pointCloud->getCenterBox());
    view->updateGPUBuffer();
}

void PointCloudRenderer::scalePointCloud(float scale)
{
    vec3 center = pointCloud->getCenterBox();

    // Center point cloud if its not centered
    if (center != vec3(0))
        updateCPUBufferCenter(center);
   
    // Scale every point from center
    for (auto& point : pointCloud->getPoints())
    {
        vec3 pos = point.get_position();
        pos *= scale;

        point.set_position(pos);
    }

    // Return point cloud to original position
    if (center != vec3(0))
        updateCPUBufferCenter(-center);

    view->updateGPUBuffer();
}

void PointCloudRenderer::rotateAroundX(float value)
{
    vec3 center = pointCloud->getCenterBox();

    // Center point cloud if its not centered
    if (center != vec3(0))
        updateCPUBufferCenter(center);

    for (auto& point : pointCloud->getPoints())
    {
        vec3 pos = point.get_position();
        pos = rotateX(pos, radians(value));

        point.set_position(pos);
    }

    // Return point cloud to original position
    if (center != vec3(0))
        updateCPUBufferCenter(-center);

    view->updateGPUBuffer();
}

#pragma endregion

#pragma region Widget methods

void PointCloudRenderer::rotateCamera(float value)
{
    cameraAngle += value * cameraMovementSpeed;

    if (cameraAngle > cameraAngleLimits.x)
        cameraAngle = cameraAngleLimits.x;
    else if (cameraAngle < cameraAngleLimits.y)
        cameraAngle = cameraAngleLimits.y;

    float y = cameraRadius * sin(radians(cameraAngle));
    float z = cameraRadius * cos(radians(cameraAngle));

    camera.transform.position = vec3(0, y, -z);
    updateViewMatrix();
}

void PointCloudRenderer::rotatePointCloudY(float value)
{
    pointCloud->transform.rotation.y -= value * modelRotationSpeed;
}

void PointCloudRenderer::zoom(int value)
{
    cameraRadius -= value * zoomSpeed;

    if (cameraRadius < zoomLimits.x)
        cameraRadius = zoomLimits.x;
    else if (cameraRadius > zoomLimits.y)
        cameraRadius = zoomLimits.y;

    rotateCamera(0);
}

#pragma endregion

void PointCloudRenderer::updateCPUBufferCenter(vec3 center)
{
    for (auto& point : pointCloud->getPoints())
    {
        vec3 pos = point.get_position();
        pos -= center;

        point.set_position(pos);
    }
}

void PointCloudRenderer::updateViewMatrix()
{
    mat4 view = camera.get_view_matrix();
    shader->bind();
    shader->setUniformMat4f("view", view);
}
