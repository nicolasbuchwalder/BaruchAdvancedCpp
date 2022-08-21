// Level6_Section1_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include <iostream>

int main() {

	Point p1{};
	Point p2{1.0, 1.0};
	std::cout << p2 << std::endl;
	Line l{ p1, p2 };
	std::cout << l << std::endl;
	Circle c{ p1, 3.14 };
	std::cout << c << std::endl;
	//=> the print function is overloaded 
	//=> the overloaded << defined in shape is used correctly by its derived classes


}