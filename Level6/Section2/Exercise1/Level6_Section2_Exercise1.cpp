// Level6_Section2_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Singleton.h"

#include <iostream>

int main() {

	Point* O = Singleton<Point>::instance();

	Point p1{1.0, 2.0};
	std::cout << "distance from default origin: " << p1.Distance() << std::endl;

	
	O->x(1.0); O->y(1.0);

	std::cout << "distance from new origin: " << p1.Distance() << std::endl;
	//=> we notice that we indeed have changed the origin

}