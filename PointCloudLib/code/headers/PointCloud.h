
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

	public:

		Transform transform;

	private:

		std::string path;
		vector< Point > points;

	public:

		PointCloud(const char* filePath);

	public:

		vector<Point>& getPoints() { return points; }
		std::string&   getPath  () { return   path; }

	private:

		void loadPointCloud(const char* filePath);
	};
}
