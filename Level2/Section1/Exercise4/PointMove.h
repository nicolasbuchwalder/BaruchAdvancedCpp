// PointMove.h: Class derived from Shape that portrays a point, has move constructors
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
#include "Shape.h"
class PointMove :
    public Shape
{
public:
    PointMove() {};
    virtual void draw() override {};
    // move sementics
    PointMove(PointMove&&) {};
    PointMove& operator=(PointMove&&) {};
};

