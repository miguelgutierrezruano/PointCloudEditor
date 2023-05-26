
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>

#include "PointCloud.h"
#include "PointCloudLoader.h"

namespace mpc
{
	PointCloud::PointCloud(const char* filePath)
	{
		loadPointCloud(filePath);
	}

	void PointCloud::loadPointCloud(const char* filePath)
	{
		// TODO: Filter file type

		PointCloudLoader::loadPLYCloud(filePath, points);
	}

	void PointCloud::center()
	{
		std::cout << "Centering point cloud" << std::endl;
	}
}