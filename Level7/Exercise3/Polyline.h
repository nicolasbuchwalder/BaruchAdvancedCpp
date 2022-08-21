// Polyline.h: This file contains the polyline class, which is a shape with any number of points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Shape.h"
#include "Point.h"

#include <vector>

//  !!!! I didn't manage to use a template template class, so the container is fixed and is a vector

class Polyline :
    public Shape
{
private:

    // vector of points
    std::vector<std::shared_ptr<Point>> points;


public:

    Polyline();  // Default constructor
    Polyline(std::vector<std::shared_ptr<Point>> new_points);  // Constructor with points
    Polyline(const Polyline& pt);  // Copy constructor
    Polyline& operator=(const Polyline& pt);  // Assignment operator

    // overriding the printing function of shape abstract class
    std::string print() const;

};

