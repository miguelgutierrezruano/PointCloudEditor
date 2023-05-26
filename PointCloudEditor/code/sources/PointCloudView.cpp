
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <OpenGLDebugger.h>

#include "PointCloudView.h"

PointCloudView::PointCloudView()
{
	
}

PointCloudView::PointCloudView(shared_ptr<PointCloud> viewPointCloud)
{
	setView(viewPointCloud);
}

void PointCloudView::setView(shared_ptr<PointCloud> viewPointCloud)
{
	pointCloud = viewPointCloud;

	vbo.upload_to_gpu(pointCloud->getPoints().data(), (unsigned int)pointCloud->getPoints().size() * sizeof(Point));
	//vbo.upload_to_gpu(myPoints.data(), (unsigned int)myPoints.size() * sizeof(Point));

	VertexBufferLayout vbLayout;
	vbLayout.push<float>(3);
	vbLayout.push<float>(3);

	vao.addBuffer(vbo, vbLayout);

	std::cout << "Data sent to GPU sucessfully" << std::endl;
}

void PointCloudView::render(shared_ptr<Shader> shader)
{
	vao.bind();
	shader->bind();

	GLClearError();
	glDrawArrays(GL_POINTS, 0, pointCloud->getPoints().size());
	GLLogCall();
}
