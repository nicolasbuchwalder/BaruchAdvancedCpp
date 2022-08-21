// Level6_Section6_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "OriginPoint.h"

// PART B)
#include "ExactDistance.h"
// PART C)
#include "ApproximateDistance.h"

#include <iostream>

int main() {

	// PART F)

	Point p1{ 0,0 };
	Point p2{ 1,1 };
	
	std::cout << "points: " << p1 << ", " << p2 << std::endl;

	Point::setStrategy(new ExactDistance);

	std::cout << "exact distance: " << p1.Distance(p2) << std::endl;

	Point::setStrategy(new ApproximateDistance);

	std::cout << "approximate distance: " << p1.Distance(p2) << std::endl;

	//=> distance has indeed changed


}