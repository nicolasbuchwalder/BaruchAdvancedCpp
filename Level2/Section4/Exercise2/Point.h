// Point.h: Class that is a 2d point
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
class Point {
public:
    double x;
    double y;

    Point(double new_x, double new_y) : x{ new_x }, y{ new_y } {};
    virtual ~Point() { std::cout << "\nPoint destructor\n"; };
    void print() const { std::cout << "x: " << x << " y: " << y << std::endl; };
};

