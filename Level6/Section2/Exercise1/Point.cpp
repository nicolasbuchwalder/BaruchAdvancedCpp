// Point.cpp: This file contains the Point class, which is a shape reprenseting a point
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Point.h"
#include "OriginPoint.h"

#include <string>
#include <cmath>


Point::Point() : // Default constructor
    _x{ new double(0)}, _y{new double(0)}{};

Point::Point(double xs, double ys) :  // Constructor with coordinates
    _x{ new double(xs) }, _y{ new double(ys) }{};

Point::Point(const Point& pt) :  // Copy constructor
    _x{ new double(*pt._x) }, _y{ new double(*pt._y) }{};

Point& Point::operator=(const Point& pt) {  // Assignment operator
    Point p(pt);
    return p;
}

double Point::x() { return *this->_x; };  // Return x coordinate
double Point::y() { return *this->_y; };  // Return y coordinate

void Point::x(double xs) {  // Set x coordinate
    delete _x;
    _x = new double(xs);
};
void Point::y(double ys) { // Set y coordinate
    delete _y;
    _y = new double(ys);
};

Point::~Point() {
    delete _x;
    delete _y;
}

// overriding the printing function of shape abstract class
std::string Point::print() {
    return "Point(" + std::to_string(this->x()) + ", " + std::to_string(this->y()) + ")";
};


// PART C)

 //function to compute the distance between this point and origin
double Point::Distance() {
	double delta_x = std::abs(*this->_x - *OriginPoint::instance()->_x);
	double delta_y = std::abs(*this->_y - *OriginPoint::instance()->_y);
	return std::sqrt(delta_x * delta_x + delta_y * delta_y);
};