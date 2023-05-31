
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

#include "PointCloud.h"
#include "PointCloudLoader.h"

namespace mpc
{
	PointCloud::PointCloud(const char* filePath)
	{
		path = filePath;
		loadPointCloud(filePath);
	}

	void PointCloud::loadPointCloud(const char* filePath)
	{
		PointCloudLoader::loadBinaryPLYCloud(filePath, points);
	}
}