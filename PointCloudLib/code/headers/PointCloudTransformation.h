
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

		/// <summary>
		/// Center point cloud in coordinates system origin
		/// </summary>
		/// <param name="cloud">Cloud to center</param>
		static void center (PointCloud& cloud);

		/// <summary>
		/// Rotate point cloud around a given axis
		/// </summary>
		/// <param name="value">Degrees to rotate</param>
		/// <param name="cloud">Cloud to rotate</param>
		/// <param name="axis">Axis to rotate around. 0x, 1y, 2z</param>
		static void rotate (float value, PointCloud& cloud, int axis);

		/// <summary>
		/// Scale point cloud
		/// </summary>
		/// <param name="value">Scale value</param>
		/// <param name="cloud">Cloud to scale</param>
		static void scale  (float value, PointCloud& cloud);

	private:

		static void invertPosition(vec3 center, PointCloud& cloud);

		static vec3 getCenterBox (PointCloud& cloud);
		static vec3 getCenterMean(PointCloud& cloud);
		static void calculateLimit(Point& point, vec2& xLimits, vec2& yLimits, vec2& zLimits);
	};
}
