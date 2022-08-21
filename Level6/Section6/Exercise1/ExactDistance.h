// ExactDistance.h: Class to calculate exaclty the distance of points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "DistanceStrategy.h"
#include "Point.h"

#include <cmath>

class ExactDistance :
    public DistanceStrategy
{
public:
    double Distance(const Point& p1, const Point& p2) {
        double delta_x = p1.x() - p2.x();
        double delta_y = p1.y() - p2.y();
        return std::sqrt(delta_x * delta_x + delta_y * delta_y);
    }
   
    
};


