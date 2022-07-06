// Point.h: This class is a point class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
class Point {
public:
    double x, y;

    Point(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    };

    void X(double new_x) {
        x = new_x;
    }

    void Y(double new_y) {
        y = new_y;
    }
};

