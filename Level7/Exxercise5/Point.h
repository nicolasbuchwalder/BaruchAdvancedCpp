// Point.h: This file contains the Point class, which is a shape reprenseting a point
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Shape.h"

#include <string>

// forward declaration
class NewDistanceStrategy;

class Point : public Shape
{
private:
	// attributes are set as pointers so that deep copy
	double* _x;
	double* _y;
	
	// PART B)

	// static pointer to NewDsitanceStrategy
	static NewDistanceStrategy* _strategy;

public:
	Point();  // Default constructor
	Point(double xs, double ys);  // Constructor with coordinates
	Point(const Point& pt);  // Copy constructor
	Point& operator=(const Point& pt);  // Assignment operator
	double x() const;  // Return x coordinate
	double y() const;  // Return y coordinate
	void x(double xs);  // Set x coordinate
	void y(double ys);  // Set y coordinate

	~Point();

	// overriding the printing function of shape abstract class
	std::string print();

	// static function to set the calculation strategy
	static void setStrategy(NewDistanceStrategy* strategy);


	// defining distances
	double Distance(const Point& p);
	double Distance();

	// PART B)
	// defining the distance with the strategy as a parameter
	double Distance(const Point& p, NewDistanceStrategy* strategy);



};

