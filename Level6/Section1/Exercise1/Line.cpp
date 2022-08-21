// Line.cpp: This file contains the Line class, which is a shape with two points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Line.h"

Line::Line() : // Default constructor
    _pt1{ new Point }, _pt2{ new Point }{};
Line::Line(const Point& pt1s, const Point& pt2s) :   // Constructor with points
    _pt1{ new Point(pt1s) }, _pt2{ new Point(pt2s) }{};
Line::Line(const Line& pt) : // Copy constructor
    _pt1{ new Point(*pt._pt1) }, _pt2{ new Point(*pt._pt2) }{};
Line& Line::operator=(const Line& pt) {  // Assignment operator
    Line l(pt);
    return l;
};
Point Line::p1() const { return *this->_pt1; };  // Return point 1
Point Line::p2() const { return *this->_pt2; };;  // Return point 2
void Line::p1(const Point& ps) {  // Set point 1
    delete _pt1;
    this->_pt1 = new Point(ps);
};
void Line::p2(const Point& ps) {  // Set point 2
    delete _pt2;
    this->_pt2 = new Point(ps);
};

// overriding the printing function of shape abstract class
std::string Line::print() const {
    return "Line( " + (*this->_pt1).print() + ", " + (*this->_pt2).print() + " )";
};