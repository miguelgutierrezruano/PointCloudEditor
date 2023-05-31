
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glm/gtx/rotate_vector.hpp>

#include "PointCloudTransformation.h"

namespace mpc
{
	void PointCloudTransformation::center(PointCloud& cloud)
	{
        vec3 center = getCenterBox(cloud);
        invertPosition(center, cloud);
	}

    void PointCloudTransformation::rotateX(float value, PointCloud& cloud)
    {
        vec3 center = getCenterBox(cloud);

        // Center point cloud if its not centered
        if (center != vec3(0))
            invertPosition(center, cloud);

        for (auto& point : cloud.points)
        {
            vec3 pos = point.get_position();
            pos = glm::rotateX(pos, radians(value));

            point.set_position(pos);
        }

        // Return point cloud to original position
        if (center != vec3(0))
            invertPosition(-center, cloud);
    }

    void PointCloudTransformation::scale(float value, PointCloud& cloud)
    {
        vec3 center = getCenterBox(cloud);

        // Center point cloud if its not centered
        if (center != vec3(0))
            invertPosition(center, cloud);

        // Scale every point from center
        for (auto& point : cloud.points)
        {
            vec3 pos = point.get_position();
            pos *= value;

            point.set_position(pos);
        }

        // Return point cloud to original position
        if (center != vec3(0))
            invertPosition(-center, cloud);
    }

    void PointCloudTransformation::invertPosition(vec3 center, PointCloud& cloud)
    {
        for (auto& point : cloud.points)
        {
            vec3 pos = point.get_position();
            pos -= center;

            point.set_position(pos);
        }
    }

    vec3 PointCloudTransformation::getCenterBox(PointCloud& cloud)
    {
        // Center of box containing the point cloud
        constexpr float min = std::numeric_limits<float>::min();
        constexpr float max = std::numeric_limits<float>::max();

        vec2 xLimits = vec2(max, min);
        vec2 yLimits = vec2(max, min);
        vec2 zLimits = vec2(max, min);

        for (auto point : cloud.points)
            calculateLimit(point, xLimits, yLimits, zLimits);

        float meanX = (xLimits.x + xLimits.y) / 2;
        float meanY = (yLimits.x + yLimits.y) / 2;
        float meanZ = (zLimits.x + zLimits.y) / 2;

        return vec3(meanX, meanY, meanZ);
    }

    vec3 PointCloudTransformation::getCenterMean(PointCloud& cloud)
    {
        // Mean of vertices
        float xCount = 0, yCount = 0, zCount = 0;

        for (auto point : cloud.points)
        {
            vec3 pos = point.get_position();
            xCount += pos.x;
            yCount += pos.y;
            zCount += pos.z;
        }

        int size = (int)cloud.points.size();
        return vec3(xCount / size, yCount / size, zCount / size);
    }

    void PointCloudTransformation::calculateLimit(Point& point, vec2& xLimits, vec2& yLimits, vec2& zLimits)
    {
        vec3 pos = point.get_position();

        // Calculate X axis
        if (pos.x < xLimits.x)
            xLimits.x = pos.x;
        else if (pos.x > xLimits.y)
            xLimits.y = pos.x;

        // Calculate Y axis
        if (pos.y < yLimits.x)
            yLimits.x = pos.y;
        else if (pos.y > yLimits.y)
            yLimits.y = pos.y;

        // Calculate Z axis
        if (pos.z < zLimits.x)
            zLimits.x = pos.z;
        else if (pos.z > zLimits.y)
            zLimits.y = pos.z;
    }
}