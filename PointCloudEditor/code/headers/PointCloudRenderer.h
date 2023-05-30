
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include "PointCloud.h"
#include "Renderer.hpp"
#include "Shader.h"
#include "PointCloudView.h"
#include "Camera.h"

using namespace mpc;
using namespace gli;

class PointCloudRenderer : public Renderer
{

private:

	int widgetWidth;
	int widgetHeight;

	std::shared_ptr<PointCloud> pointCloud;
	std::shared_ptr<Shader    > shader;

	Camera camera;
	PointCloudView* view;

	float cameraRadius;
	float cameraAngle;

	float zoomSpeed;
	float cameraMovementSpeed;
	float modelRotationSpeed;

	vec2 cameraAngleLimits;
	vec2 zoomLimits;

public:

	PointCloudRenderer();
   ~PointCloudRenderer();

public:

	void initialize() override;
	void resize(int newWidth, int newHeight) override;
	void render() override;

	void setupPointCloud(std::shared_ptr<PointCloud> newPointCloud);

	// Editor methods
	void centerPointCloud();
	void changeFieldOfView (float fov);
	void changePointSize   (float pointSize);

	// Widget methods
	void zoom(int value);
	void rotateCamera     (float value);
	void rotatePointCloudY(float value);

	const std::shared_ptr<PointCloud> const getPointCloud()
	{
		return pointCloud;
	}

private:

	void updateBuffersCenter(vec3 center);
	void updateViewMatrix();
};
