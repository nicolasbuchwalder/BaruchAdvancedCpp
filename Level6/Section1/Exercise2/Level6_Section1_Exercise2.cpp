// Level6_Section1_Exercise2.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include <iostream>

int main() {

	Point p1{};
	Point p2{1.0, 1.0};
	std::cout << "length between " << p1 << " and " << p2 << ": " << p1.Distance(p2) << std::endl;
	Point p3{ 2.0, 0.0 };

	Line l1{ p1, p2 };
	std::cout << "line: " << l1 << ", length: " << l1.Length() << std::endl;
	//=> distance works just like lenght 
	Line l2{ p1, p3 };
	std::cout << "line: " << l2 << ", length: " << l2.Length() << std::endl;


}