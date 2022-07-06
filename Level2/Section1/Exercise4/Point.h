// Point.h: Class derived from Shape that portrays a point 
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course#pragma once

#include "Shape.h"
// GIVEN CODE

class Point : public Shape {
public:
    Point() {};
    virtual void draw() override {};
    // added a copy ans assignment constructors to the given class
    Point(const Point&) {};
    Point operator=(const Point&) {};

};

