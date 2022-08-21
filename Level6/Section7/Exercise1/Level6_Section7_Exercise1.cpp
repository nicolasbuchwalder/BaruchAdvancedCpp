// Level6_Section7_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

// PART A, B)
#include "ShapeFactory.h"

// PART C, D)
#include "ConsoleShapeFactory.h"

#include <iostream>

int main() {

	ShapeFactory* console{ new ConsoleShapeFactory };

	auto p{ console->CreatePoint()};
	std::cout << "created: " << *p << std::endl;

	auto l{ console->CreateLine() };
	std::cout << "created: " << *l << std::endl;

	auto c{ console->CreateCircle() };
	std::cout << "created: " << *c << std::endl;

	// => everything works as expected


}