
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>

#include "Point.h"
#include "Transform.h"

using std::vector;

namespace mpc
{
	class API PointCloud
	{

	public:

		Transform transform;

	private:

		vector< Point > points;

	public:

		PointCloud(const char* filePath);

	public:

		vector<Point>& getPoints() { return points; }

		void calculateLimit(Point& point, vec2& xLimits, vec2& yLimits, vec2& zLimits);

	private:

		void loadPointCloud(const char* filePath);
	};
}
