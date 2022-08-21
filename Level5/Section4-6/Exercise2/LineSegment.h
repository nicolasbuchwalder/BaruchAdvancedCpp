#pragma once

#include "Point.h"

#include <boost/functional/hash.hpp>

class LineSegment
{
private:
	Point pointA;
	Point pointB;

public:
    // default constructor
    LineSegment() {};
    // value constructor
    LineSegment(Point A, Point B) : pointA{ A }, pointB{ B } {};
    // copy constructor
    LineSegment(const LineSegment& copy) {
        this->pointA = copy.pointA;
        this->pointB = copy.pointB;
    };
    // assigment
    void operator=(const LineSegment& copy) {
        this->pointA = copy.pointA;
        this->pointB = copy.pointB;
    };
    // member functions to access coordinates
    Point A() const { return pointA; };
    Point B() const { return pointB; };

    // PART A)

    // function to hash LineSegment instance
    static std::size_t hash(const LineSegment& ls) {
        std::size_t seed{ 0 };
        boost::hash_combine(seed, Point::hash(ls.pointA));
        boost::hash_combine(seed, Point::hash(ls.pointB));
        return seed;
    }
};

