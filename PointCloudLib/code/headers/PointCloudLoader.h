
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>
#include <string>

#include "Point.h"

namespace mpc
{
	class PointCloudLoader
	{

	public:

		static void loadPLYCloud(const std::string& path, std::vector<Point>& points);
	};
}
