// PointNoCopyAssign.h: Class derived from Shape that portrays a point, but now has deleted copy and assign constructors
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
#include "Shape.h"
// copying class and doing the modifications for deleted copy and assigment
class PointNoCopyAssign : public Shape {
public:
    PointNoCopyAssign() {};
    // copy and assign constructors now deleted
    PointNoCopyAssign(const PointNoCopyAssign&) = delete;
    PointNoCopyAssign operator=(const PointNoCopyAssign&) = delete;
    virtual void draw() override {};
};
