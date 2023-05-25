
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>

#include "PointCloud.h"

namespace mpc
{
	PointCloud::PointCloud(const char* filePath)
	{
		loadPointCloud(filePath);
	}

	void PointCloud::loadPointCloud(const char* filePath)
	{
		Point point1(glm::vec3(-0.5f, -0.5f, 0), glm::vec4(1, 0, 0, 1));
		Point point2(glm::vec3( 0.5f, -0.5f, 0), glm::vec4(0, 1, 0, 1));
		Point point3(glm::vec3(    0,  0.5f, 0), glm::vec4(0, 0, 1, 1));

		points.push_back(point1);
		points.push_back(point2);
		points.push_back(point3);
	}

	void PointCloud::center()
	{
		std::cout << "Centering point cloud" << std::endl;
	}
}