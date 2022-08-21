// Line.h: This file contains the Line class, which is a shape with two points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Shape.h"
#include "Point.h"

class Line :
    public Shape
{
private:
    // attributes are set as pointers so that deep copy
    Point* _pt1;
    Point* _pt2;


public:

    Line();  // Default constructor
    Line(const Point& pt1s, const Point& pt2s);  // Constructor with points
    Line(const Line& pt);  // Copy constructor
    Line& operator=(const Line& pt);  // Assignment operator
    Point p1() const;  // Return point 1
    Point p2() const;  // Return point 2
    void p1(const Point& ps);  // Set point 1
    void p2(const Point& ps);  // Set point 2

    // overriding the printing function of shape abstract class
    std::string print() const;

    // PART D, E)

    // function to compute length of line
    double Length();

    void Accept(ShapeVisitor& visitor);
};

