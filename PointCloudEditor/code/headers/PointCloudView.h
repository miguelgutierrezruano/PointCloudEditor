
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <memory>

#include "PointCloud.h"

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <vector>

using namespace gli;
using namespace mpc;

using std::shared_ptr;

// Class to convert model data into GPU data and render it 
class PointCloudView
{
	shared_ptr< PointCloud > pointCloud;

	VertexArray  vao;
	VertexBuffer vbo;

	float pointSize;
	
public:

	PointCloudView();

	PointCloudView(shared_ptr< PointCloud > viewPointCloud);

public:

	void render(shared_ptr< Shader > shader);

	void setView(shared_ptr< PointCloud > viewPointCloud);
	void setPointSize(float newPointSize);

	void updateGPUBuffer();
};