// Level6_Section8_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"

// PART F-K)
#include "NameDecorator.h"

#include <iostream>

int main() {

	NameDecorator O;
	O.SetName("Origin");
	O.SetShape(std::make_shared<Point>(0, 0));

	std::cout << O.GetName() << ": " << *O.GetShape() << std::endl;

	NameDecorator A(std::make_shared<Point>(1, 1), "A");

	std::cout << A.GetName() << ": " << *A.GetShape() << std::endl;

	//=> works as expected

}