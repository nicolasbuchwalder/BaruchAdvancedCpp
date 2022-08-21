// Point.h: This file contains the point class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include <cmath>
#include <boost/functional/hash.hpp>


class Point
{
private:
    int _x{};
    int _y{};

public:
    // default constructor
    Point() {};
    // value constructor
    Point(int x, int y) : _x{ x }, _y{ y } {};
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
    int x() const { return _x; };
    int y() const { return _y; };

    // PART A)

    // the unordered_multiset needed the == operator to work
    bool operator==(const Point& other) const {
        return ((other.x() == _x) && (other.y() == _y));
    }
};


