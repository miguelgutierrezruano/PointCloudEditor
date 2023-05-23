
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include "PointCloud.h"
#include "Renderer.hpp"

using namespace mpc;
using namespace gli;

class PointCloudRenderer : public Renderer
{
	// Everything from MGRenderer

private:

	PointCloud pointCloud;

public:

	PointCloudRenderer();

public:

	void initialize() override;
	void resize(int newWidth, int newHeight) override;
	void render() override;
};
