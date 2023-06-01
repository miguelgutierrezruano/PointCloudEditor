
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

/// <summary>
/// OpenGL representation of a PointCloud
/// </summary>
class PointCloudView
{
	shared_ptr< PointCloud > pointCloud;

	VertexArray  vao;
	VertexBuffer vbo;

	float pointSize;
	
public:

	/// <summary>
	/// Create empty PointCloud
	/// </summary>
	PointCloudView();

	/// <summary>
	/// Create PointCloud in GPU
	/// </summary>
	/// <param name="viewPointCloud">PointCloud object to render</param>
	PointCloudView(shared_ptr< PointCloud > viewPointCloud);

public:

	/// <summary>
	/// Render PointCloud in OpenGL context with given shader
	/// </summary>
	/// <param name="shader"></param>
	void render(shared_ptr< Shader > shader);

	/// <summary>
	/// Create PointCloud in GPU
	/// </summary>
	/// <param name="viewPointCloud">PointCloud object to render</param>
	void setView(shared_ptr< PointCloud > viewPointCloud);

	/// <summary>
	/// Change point size
	/// </summary>
	/// <param name="newPointSize">New point size</param>
	void setPointSize(float newPointSize);

	/// <summary>
	/// Update GPU buffer data of viewPointCloud
	/// </summary>
	void updateGPUBuffer();
};