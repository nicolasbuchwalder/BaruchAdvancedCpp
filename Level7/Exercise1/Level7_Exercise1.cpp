// Level7_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

// PART A)
#include "ShapeFactory.h"
#include "ConsoleShapeFactory.h"

#include <iostream>

int main() {
	
	// PART B)
	ShapeFactory* console{ new ConsoleShapeFactory };

	auto t{ console->CreateShapes()};
	std::cout << "created: " << *std::get<0>(t) << ", " << *std::get<1>(t) << ", " << *std::get<2>(t) << std::endl;
	// => everything works as expected
	
	// PART C)
	// The code is cleaner but it would be a bit more cumbersome to add new shapes because the user needs
	// to add them to the tuple, so it's an additionnal thing to add


}