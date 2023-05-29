
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <glad/glad.h>

#include "Point.h"
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
    glEnable(GL_MULTISAMPLE);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.15f, 0.15f, 0.15f, 1.f);

    shader = std::make_shared<Shader>("../code/shaders/PointCloudShader.shader");

    //pointCloud = std::make_shared<PointCloud>("../resources/pyramid.ply");
    //pointCloud = std::make_shared<PointCloud>("../resources/pyramid-copy.ply");
    pointCloud = std::make_shared<PointCloud>("../resources/boat.ply");
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
    {
        // Center of box containing the point cloud
        constexpr float min = std::numeric_limits<float>::min();
        constexpr float max = std::numeric_limits<float>::max();

        vec2 xLimits = vec2(max, min);
        vec2 yLimits = vec2(max, min);
        vec2 zLimits = vec2(max, min);

        for (auto point : pointCloud->getPoints())
            pointCloud->calculateLimit(point, xLimits, yLimits, zLimits);

        float meanX = (xLimits.x + xLimits.y) / 2;
        float meanY = (yLimits.x + yLimits.y) / 2;
        float meanZ = (zLimits.x + zLimits.y) / 2;
        vec3 center = vec3(meanX, meanY, meanZ);

        // Mean of vertices
        /*float xCount = 0, yCount = 0, zCount = 0;

        for (auto point : pointCloud->getPoints())
        {
            vec3 pos = point.get_position();
            xCount += pos.x;
            yCount += pos.y;
            zCount += pos.z;
        }

        int size = pointCloud->getPoints().size();
        vec3 center = vec3(xCount / size, yCount / size, zCount / size);*/
        updateBuffersCenter(center);
    }
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
