// Point.h: This file contains the Point class, which is a shape reprenseting a point
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Shape.h"

#include <string>


class Point : public Shape
{
private:
	// attributes are set as pointers so that deep copy
	double* _x;
	double* _y;

public:
	Point();  // Default constructor
	Point(double xs, double ys);  // Constructor with coordinates
	Point(const Point& pt);  // Copy constructor
	Point& operator=(const Point& pt);  // Assignment operator
	double x() const;  // Return x coordinate
	double y() const;  // Return y coordinate
	void x(double xs);  // Set x coordinate
	void y(double ys);  // Set y coordinate

	// overriding the printing function of shape abstract class
	std::string print() const;
};

