
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include "PointCloud.h"
#include "Renderer.hpp"
#include "Shader.h"
#include "PointCloudView.h"

using namespace mpc;
using namespace gli;

class PointCloudRenderer : public Renderer
{
	// Everything from MGRenderer

private:

	std::shared_ptr<PointCloud> pointCloud;
	std::shared_ptr<Shader    > shader;

	PointCloudView* view;

public:

	PointCloudRenderer();

public:

	void initialize() override;
	void resize(int newWidth, int newHeight) override;
	void render() override;

	void setupPointCloud(std::shared_ptr<PointCloud> newPointCloud);
};
