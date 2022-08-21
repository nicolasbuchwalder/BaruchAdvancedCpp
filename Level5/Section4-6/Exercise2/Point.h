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

    // function to hash Point instance
    static std::size_t hash(const Point& p) {
        std::size_t seed{ 0 };
        boost::hash_combine(seed, p.x());
        boost::hash_combine(seed, p.y());
        return seed;
    }
};

