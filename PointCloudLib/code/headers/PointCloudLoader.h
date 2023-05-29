
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>
#include <string>

#include "API.h"

namespace mpc
{
	class Point;

	class API PointCloudLoader
	{

	public:

		static bool generateCopy(const std::string& path, std::vector<Point>& points);
		static void loadPLYCloud(const std::string& path, std::vector<Point>& points);
		static void loadBinaryPLYCloud(const std::string& path, std::vector<Point>& points);

	private:

		static std::string getFilenameFromPath(const std::string& path);
		static std::string getParentPath(const std::string& path);
	};
}
