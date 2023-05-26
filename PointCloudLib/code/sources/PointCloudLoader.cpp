
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <fstream>
#include <sstream>

#include "PointCloudLoader.h"

using std::vector;
using namespace glm;

namespace mpc
{
	void PointCloudLoader::loadPLYCloud(const std::string& path, std::vector<Point>& points)
	{
		std::ifstream file(path);
		std::string line;

		// Skip header
		while (line != "end_header")
		{
			std::getline(file, line);
		}

		while (std::getline(file, line))
		{
			std::istringstream iss(line);

			vec3 pos(0);
			vec3 color(0);

			iss >> pos.x >> pos.y >> pos.z;
			iss >> color.x >> color.y >> color.z;

			points.push_back(Point(pos, glm::vec4(color.x, color.y, color.z, 1)));
		}
	}
}