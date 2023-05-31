
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>
#include <string>

#include "Point.h"
#include "Transform.h"

using std::vector;

namespace mpc
{
	class API PointCloud
	{

		friend class PointCloudTransformation;
		friend class PointCloudLoader;

	public:

		Transform transform;

	private:

		std::string path;
		vector< Point > points;

	public:

		PointCloud(const char* filePath);

	public:

		const vector<Point>& getPoints() const { return points; }
		std::string&         getPath  ()       { return   path; }

	private:

		void loadPointCloud(const char* filePath);
	};
}
