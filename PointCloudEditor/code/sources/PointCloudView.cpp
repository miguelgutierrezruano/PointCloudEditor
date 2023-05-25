//
//// Distributed under MIT License
//// @miguelgutierrezruano
//// 2023
//
//#include "PointCloudView.h"
//
//PointCloudView::PointCloudView()
//{
//
//}
//
//PointCloudView::PointCloudView(shared_ptr<PointCloud> viewPointCloud)
//{
//	setView(viewPointCloud);
//}
//
//void PointCloudView::setView(shared_ptr<PointCloud> viewPointCloud)
//{
//	pointCloud = viewPointCloud;
//
//	vbo.upload_to_gpu(pointCloud->getPoints().data(), (unsigned int)pointCloud->getPoints().size() * sizeof(Point));
//
//	VertexBufferLayout vbLayout;
//	vbLayout.push<float>(3);
//	vbLayout.push<float>(4);
//
//	vao.addBuffer(vbo, vbLayout);
//}
//
//void PointCloudView::render(shared_ptr<Shader> shader)
//{
//	vao.bind();
//	shader->bind();
//
//	glDrawArrays(GL_POINTS, 0, pointCloud->getPoints().size());
//}
