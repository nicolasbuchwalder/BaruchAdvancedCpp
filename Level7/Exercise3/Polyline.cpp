// Polyline.cpp: This file contains the polyline class, which is a shape with any number of points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Polyline.h"

#include "Point.h"


Polyline::Polyline() {};// Default constructor

Polyline::Polyline(std::vector<std::shared_ptr<Point>> new_points) :   // Constructor with points
    points(new_points) {};

Polyline::Polyline(const Polyline& pt) { // Copy constructor
    this->points = pt.points;
}
Polyline& Polyline::operator=(const Polyline& pt) {  // Assignment operator
    Polyline pl(pt);
    return pl;
};
// overriding the printing function of shape abstract class
std::string Polyline::print() const {
    std::string out_string{ "Polyline( " };
    for (auto point : this->points) {
        out_string += (*point).print() + ", ";
    }
    return out_string + " )";
};
