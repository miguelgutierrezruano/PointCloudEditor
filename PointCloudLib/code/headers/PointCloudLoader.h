
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>
#include <string>

#include "API.h"

namespace happly
{
	class PLYData;
}

namespace mpc
{
	class Point;

	class API PointCloudLoader
	{

	public:

		static void loadBinaryPLYCloud    (const std::string& path, std::vector<Point>& points);
		static void saveBinaryPLYCloud    (const std::string& path, std::vector<Point>& points);
		static bool generateBinaryPLYCopy (const std::string& path, std::vector<Point>& points);

	private:

		static std::string getFilenameFromPath(const std::string& path);
		static std::string getParentPath(const std::string& path);

		static happly::PLYData getPLYDataFromPoints(std::vector<Point>& points);

		static std::string getCopyName(const std::string& path);
	};
}
