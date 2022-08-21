// Point.h: This file contains the point class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include <cmath>


class Point
{
private:
    double _x{};
    double _y{};

public:
    // default constructor
    Point() {};
    // value constructor
    Point(double x, double y) : _x{ x }, _y{ y } {};
    // copy constructor
    Point(const Point& copy) {
        this->_x = copy._x;
        this->_y = copy._y;
    };
    // assigment
    void operator=(const Point& copy) {
        this->_x = copy._x;
        this->_y = copy._y;
    };
    // member functions to access coordinates
    double x() const { return _x; };
    double y() const { return _y; };

    // function to compute distance between points
    double compute_distance(const Point& other) {
        return std::sqrt((this->_x - other._x) * (this->_x - other._x) + (this->_y - other._y) * (this->_y - other._y));
    };
    
    // overloading equal signs to check if they are the same
    bool operator== (const Point& other) const{
        return (this->_x == other._x) && (this->_y == other._y);
    };
};

