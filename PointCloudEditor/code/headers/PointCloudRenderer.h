
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

	vec3 cameraInitialPosition;

public:

	PointCloudRenderer();
   ~PointCloudRenderer();

public:

	/// <summary>
	/// Override initialize method called before any OpenGL render
	/// </summary>
	void initialize() override;

	/// <summary>
	/// Override resize method called when QApplication size changes
	/// </summary>
	void resize(int newWidth, int newHeight) override;

	/// <summary>
	/// Render PointCloud in GLContext
	/// </summary>
	void render() override;

	// Set up point cloud smart pointer and create view
	void setupPointCloud(std::shared_ptr<PointCloud> newPointCloud);

	// View

	// Reset camera to its initial position
	void resetView();

	// Change field of view
	void changeFieldOfView (float fov);

	// Change point size of renderer
	void changePointSize   (float pointSize);

	// Editor methods

	// Center point cloud in coordinates origin and upload data
	void centerPointCloud();

	// 
	void scalePointCloud(float scale);
	void rotateAround(float value, int axis);

	// Widget methods
	void zoom(int value);
	void rotateCamera     (float value);
	void rotatePointCloudY(float value);

	const std::shared_ptr<PointCloud> const getPointCloud()
	{
		return pointCloud;
	}

private:

	void updateViewMatrix();
};
