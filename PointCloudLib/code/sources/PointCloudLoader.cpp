
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include <happly.h>

#include "Point.h"
#include "PointCloudLoader.h"

using std::vector;
using namespace glm;

using namespace happly;

namespace mpc
{
	bool PointCloudLoader::generateCopy(const std::string& path, std::vector<Point>& points)
	{
		// Load source file
		std::ifstream sourceFile(path, std::ios::binary);
		if (!sourceFile)
		{
			std::cout << "Failed to load source file " << path << std::endl;
			return false;
		}

		// Get name and add -copy
		std::string fileName = getFilenameFromPath(path);
		std::size_t dotIndex = fileName.find('.');
		if (dotIndex != std::string::npos)
			fileName = fileName.substr(0, dotIndex) + "-copy" + fileName.substr(dotIndex);

		// Get directory
		std::string parentPath = getParentPath(path);

		// Full path
		std::string destinationName = parentPath + "/" + fileName;

		// Create new file
		std::ofstream destinationFile(destinationName, std::ios::binary);
		if (!destinationFile) {
			std::cout << "Failed to create destination file: " << destinationName << std::endl;
			return false;
		}

		// Copy header
		std::string line;
		while (line.find(std::string("end_header")) == std::string::npos)
		{
			std::getline(sourceFile, line);
			destinationFile << line << std::endl;
		}

		// Write point data
		for (auto& point : points)
		{
			vec3 pos = point.get_position();
			vec3 color = point.get_color();
			color *= 255.f;

			destinationFile << pos.x << " " << pos.y << " " << pos.z << " "
				<< color.r << " " << color.g << " " << color.b << std::endl;
		}

		std::cout << fileName << " saved successfully!" << std::endl;
		std::cout << "Path: " << destinationName << std::endl;

		sourceFile.close();
		destinationFile.close();

		return true;
	}

	void PointCloudLoader::loadPLYCloud(const std::string& path, std::vector<Point>& points)
	{
		std::ifstream file(path);
		std::string line;

		if (!file)
		{
			std::cout << "Failed to open file: " << path << std::endl;
			return;
		}

		// Skip header
		while (line != "end_header")
		{
			std::getline(file, line);

			if (line.find("element vertex") != std::string::npos)
			{
				// Extract the size
				std::istringstream iss(line);
				std::string element, vertex;
				int size;
				iss >> element >> vertex >> size;

				points.resize((size_t)size);
			}
		}

		unsigned int pointCount = 0;

		while (std::getline(file, line))
		{
			std::istringstream iss(line);

			vec3 pos(0);
			vec3 color(0);

			iss >> pos.x >> pos.y >> pos.z;
			iss >> color.x >> color.y >> color.z;

			// Color range 0-1
			color /= 255.f;

			points[pointCount++] = Point(pos, color);
		}
	}

	void PointCloudLoader::loadBinaryPLYCloud(const std::string& path, std::vector<Point>& points)
	{
		PLYData plyIn(path.c_str());

		plyIn.validate();

		std::cout << "Loading " << path << " please wait..." << std::endl;

		points.resize(plyIn.getElement("vertex").count);

		vector<float> vertexPosX = plyIn.getElement("vertex").getProperty<float>("x");
		vector<float> vertexPosY = plyIn.getElement("vertex").getProperty<float>("y");
		vector<float> vertexPosZ = plyIn.getElement("vertex").getProperty<float>("z");

		vector<unsigned char> vertexColorX = plyIn.getElement("vertex").getProperty<unsigned char>("red");
		vector<unsigned char> vertexColorY = plyIn.getElement("vertex").getProperty<unsigned char>("green");
		vector<unsigned char> vertexColorZ = plyIn.getElement("vertex").getProperty<unsigned char>("blue");

		for (int i = 0; i < points.size(); i++)
		{
			vec3 pos(vertexPosX[i], vertexPosY[i], vertexPosZ[i]);
			vec3 color(vertexColorX[i], vertexColorY[i], vertexColorZ[i]);
			color /= 255.f;

			points[i] = Point(pos, color);
		}
	}

	std::string PointCloudLoader::getFilenameFromPath(const std::string& path)
	{
		std::filesystem::path filePath(path);
		return filePath.filename().string();
	}

	std::string PointCloudLoader::getParentPath(const std::string& path)
	{
		std::filesystem::path fullPath(path);
		return fullPath.parent_path().string();
	}
}