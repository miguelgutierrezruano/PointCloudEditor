
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "API.h"

using namespace glm;

namespace mpc
{
	class Point;

	class API PointCloudTransformation
	{

	public:

		static void center (std::vector<Point>& points);
		static void rotateX(float value, std::vector<Point>& points);
		static void rotateY(float value, std::vector<Point>& points);
		static void rotateZ(float value, std::vector<Point>& points);
		static void scale  (float value, std::vector<Point>& points);

	private:

		static vec3 getCenterBox (std::vector<Point>& points);
		static vec3 getCenterMean(std::vector<Point>& points);
	};
}
