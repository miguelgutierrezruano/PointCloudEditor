
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include "PointCloud.h"
#include "Renderer.hpp"
#include "PointCloudView.h"

using namespace mpc;
using namespace gli;

class PointCloudRenderer : public Renderer
{
	// Everything from MGRenderer

private:

	std::shared_ptr<PointCloud> pointCloud;
	PointCloudView view;

public:

	PointCloudRenderer();

public:

	void initialize() override;
	void resize(int newWidth, int newHeight) override;
	void render() override;

	void setPointCloud(std::shared_ptr<PointCloud> newPointCloud);
};
