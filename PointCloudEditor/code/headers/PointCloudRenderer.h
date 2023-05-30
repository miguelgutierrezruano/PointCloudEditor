
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
	void rotatePointCloudX (float value);
	void rotatePointCloudY (float value);
	void rotatePointCloudZ (float value);

	// Widget methods
	void updateMouseMovement(vec2 positionDiff);
	void updateMouseRotation(vec2 positionDiff);
	void zoom(int value);

	const std::shared_ptr<PointCloud> const getPointCloud()
	{
		return pointCloud;
	}

private:

	void updateBuffersCenter(vec3 center);
	void updateViewMatrix();
};
