
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

	vec3 PointCloud::getCenterMean()
	{
		// Mean of vertices
		float xCount = 0, yCount = 0, zCount = 0;

		for (auto point : points)
		{
			vec3 pos = point.get_position();
			xCount += pos.x;
			yCount += pos.y;
			zCount += pos.z;
		}

		int size = (int)points.size();
		return vec3(xCount / size, yCount / size, zCount / size);
	}

	vec3 PointCloud::getCenterBox()
	{
		// Center of box containing the point cloud
		constexpr float min = std::numeric_limits<float>::min();
		constexpr float max = std::numeric_limits<float>::max();

		vec2 xLimits = vec2(max, min);
		vec2 yLimits = vec2(max, min);
		vec2 zLimits = vec2(max, min);

		for (auto point : points)
			calculateLimit(point, xLimits, yLimits, zLimits);

		float meanX = (xLimits.x + xLimits.y) / 2;
		float meanY = (yLimits.x + yLimits.y) / 2;
		float meanZ = (zLimits.x + zLimits.y) / 2;

		return vec3(meanX, meanY, meanZ);
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