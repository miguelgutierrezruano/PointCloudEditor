
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "PointCloud.h"
#include "API.h"

using namespace glm;

namespace mpc
{
	class Point;

	class API PointCloudTransformation
	{

	public:

		static void center (PointCloud& cloud);
		static void rotate (float value, PointCloud& cloud, int axis); // 0 x 1 y 2 z
		static void scale  (float value, PointCloud& cloud);

	private:

		static void invertPosition(vec3 center, PointCloud& cloud);

		static vec3 getCenterBox (PointCloud& cloud);
		static vec3 getCenterMean(PointCloud& cloud);
		static void calculateLimit(Point& point, vec2& xLimits, vec2& yLimits, vec2& zLimits);
	};
}
