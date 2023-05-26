
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
		glm::vec3 center;

	public:

		PointCloud(const char* filePath);

	public:

		const vector<Point>& getPoints() const { return points; }

		// Should be on controller
		void centerPointCloud();

	private:

		void loadPointCloud(const char* filePath);
		void calculateLimit(Point& point, vec2& xLimits, vec2& yLimits, vec2& zLimits);
	};
}
