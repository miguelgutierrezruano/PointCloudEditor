
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
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
		// TODO: Filter file type

		PointCloudLoader::loadPLYCloud(filePath, points);
	}

	void PointCloud::calculateLimit(Point& point, vec2& xLimits, vec2& yLimits, vec2& zLimits)
	{
		vec3 pos = point.get_position();

		// Calculate X axis
		if (pos.x < xLimits.x)
			xLimits.x = pos.x;
		else if (pos.x > xLimits.y)
			xLimits.y = pos.x;

		// Calculate Y axis
		if (pos.y < yLimits.x)
			yLimits.x = pos.y;
		else if (pos.y > yLimits.y)
			yLimits.y = pos.y;

		// Calculate Z axis
		if (pos.z < zLimits.x)
			zLimits.x = pos.z;
		else if (pos.z > zLimits.y)
			zLimits.y = pos.z;
	}
}