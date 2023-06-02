
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <OpenGLDebugger.h>

#include "PointCloudView.h"

PointCloudView::PointCloudView(shared_ptr<PointCloud> viewPointCloud) : pointSize(1), changeGPUBuffer(true)
{
	pointCloud = viewPointCloud;

	vbo.upload_to_gpu(pointCloud->getPoints().data(), (unsigned int)pointCloud->getPoints().size() * sizeof(Point));

	VertexBufferLayout vbLayout;
	vbLayout.push<float>(3);
	vbLayout.push<float>(3);

	vao.addBuffer(vbo, vbLayout);

	std::cout << "Data sent to GPU sucessfully" << std::endl;
}

void PointCloudView::setPointSize(float newPointSize)
{
	pointSize = newPointSize;
}

void PointCloudView::updateGPUBuffer()
{
	vbo.bind();

	changeGPUBuffer = true;

	// Update point data
	//glBufferSubData(GL_ARRAY_BUFFER, 0, (unsigned int)pointCloud->getPoints().size() * sizeof(Point), pointCloud->getPoints().data());
}

void PointCloudView::render(shared_ptr<Shader> shader)
{
	vao.bind();
	shader->bind();

	mat4 modelMatrix = pointCloud->transform.get_matrix();
	shader->setUniformMat4f("model", modelMatrix);

	glPointSize(pointSize);

	GLClearError();

	if (changeGPUBuffer)
	{
		glBufferData(GL_ARRAY_BUFFER, (unsigned int)pointCloud->getPoints().size() * sizeof(Point), pointCloud->getPoints().data(), GL_STATIC_DRAW);
		changeGPUBuffer = false;
	}

	glDrawArrays(GL_POINTS, 0, pointCloud->getPoints().size());
	GLLogCall();
}
