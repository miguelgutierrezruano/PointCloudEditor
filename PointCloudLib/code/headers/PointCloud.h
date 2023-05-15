
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>

#include "Point.h"

using std::vector;

namespace mpc
{
	class PointCloud
	{

	private:

		vector< Point > points;

	public:

		PointCloud(const char* filePath);

	private:

		void loadPointCloud(const char* filePath);
	};
}
