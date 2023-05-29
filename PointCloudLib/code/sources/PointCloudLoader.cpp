
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

	bool PointCloudLoader::generateBinaryPLYCopy(const std::string& path, std::vector<Point>& points)
	{
		PLYData plyOut;

		vector<float> vertexPosX(points.size());
		vector<float> vertexPosY(points.size());
		vector<float> vertexPosZ(points.size());

		vector<unsigned char> vertexColorX(points.size());
		vector<unsigned char> vertexColorY(points.size());
		vector<unsigned char> vertexColorZ(points.size());

		for (int i = 0; i < points.size(); i++)
		{
			vec3 pos   = points[i].get_position();
			vec3 color = points[i].get_color();
			color *= 255.f;

			vertexPosX[i] = pos.x;
			vertexPosY[i] = pos.y;
			vertexPosZ[i] = pos.z;

			vertexColorX[i] = color.r;
			vertexColorY[i] = color.g;
			vertexColorZ[i] = color.b;
		}

		plyOut.addElement("vertex", points.size());

		plyOut.getElement("vertex").addProperty<float>("x", vertexPosX);
		plyOut.getElement("vertex").addProperty<float>("y", vertexPosY);
		plyOut.getElement("vertex").addProperty<float>("z", vertexPosZ);

		plyOut.getElement("vertex").addProperty<unsigned char>("red", vertexColorX);
		plyOut.getElement("vertex").addProperty<unsigned char>("green", vertexColorY);
		plyOut.getElement("vertex").addProperty<unsigned char>("blue", vertexColorZ);

		// Full path
		std::string destinationName = getCopyName(path);

		// Create new file
		std::ofstream destinationFile(destinationName, std::ios::binary);
		if (!destinationFile)
		{
			std::cout << "Failed to create " << destinationName << std::endl;
			return false;
		}

		plyOut.write(destinationFile, DataFormat::Binary);
		
		std::cout << destinationName << " copied successfully!" << std::endl;
		return true;
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

	std::string PointCloudLoader::getCopyName(const std::string& path)
	{
		// Get name and add -copy
		std::string fileName = getFilenameFromPath(path);
		std::size_t dotIndex = fileName.find('.');
		if (dotIndex != std::string::npos)
			fileName = fileName.substr(0, dotIndex) + "-copy" + fileName.substr(dotIndex);

		// Get directory
		std::string parentPath = getParentPath(path);

		// Full path
		return parentPath + "/" + fileName;
	}
}