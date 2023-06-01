
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
	/// <summary>
	/// Point cloud definition
	/// </summary>
	class API PointCloud
	{
		// Friend classes to improve encapsulation
		friend class PointCloudTransformation;
		friend class PointCloudLoader;

	public:

		Transform transform;

	private:

		std::string path;
		vector< Point > points;

	public:

		/// <summary>
		/// Create point cloud from path
		/// </summary>
		/// <param name="filePath">Path to the point cloud file</param>
		PointCloud(const char* filePath);

	public:

		const vector<Point>& getPoints() const { return points; }
		std::string&         getPath  ()       { return   path; }

	private:

		void loadPointCloud(const char* filePath);
	};
}
