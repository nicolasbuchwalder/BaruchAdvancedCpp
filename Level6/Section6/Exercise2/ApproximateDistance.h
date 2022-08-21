// ApproximateDistance.h: Class to calculate approximately the distance of points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "DistanceStrategy.h"
#include "Point.h"
class ApproximateDistance :
    public DistanceStrategy
{
public:
    double Distance(const Point& p1, const Point& p2) {
        return std::abs(p1.x() - p2.x()) + std::abs(p1.y() - p2.y());
    };
};