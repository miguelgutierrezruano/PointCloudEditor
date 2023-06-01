
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include <vector>
#include <string>

#include "PointCloud.h"
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

		/// <summary>
		/// Load PLY files as point clouds
		/// </summary>
		/// <param name="path">Path to point cloud file</param>
		/// <param name="cloud">Point cloud where to save loaded data</param>
		static void loadBinaryPLYCloud    (const std::string& path, PointCloud& cloud);

		/// <summary>
		/// Save PointCloud in PLY file
		/// </summary>
		/// <param name="path">Path to the PLY file</param>
		/// <param name="cloud">Cloud to save</param>
		static void saveBinaryPLYCloud    (const std::string& path, PointCloud& cloud);

		/// <summary>
		/// Generate copy of selected PointCloud
		/// </summary>
		/// <param name="path">Path where the current point cloud is</param>
		/// <param name="cloud">Cloud to save</param>
		/// <returns></returns>
		static bool generateBinaryPLYCopy (const std::string& path, PointCloud& cloud);

	private:

		static std::string getFilenameFromPath(const std::string& path);
		static std::string getParentPath(const std::string& path);

		static happly::PLYData getPLYDataFromPoints(std::vector<Point>& points);

		static std::string getCopyName(const std::string& path);
	};
}
