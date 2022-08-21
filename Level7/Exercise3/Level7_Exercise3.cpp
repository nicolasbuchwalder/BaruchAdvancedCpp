// Level7_Exercise3.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
// PART B)
#include "Polyline.h"

// PART A) => see CreateLine method (not anymore in ConsoleShapeFactory)
// PART B) => see CreatePolyline method
#include "ShapeFactory.h"

#include "ConsoleShapeFactory.h"

#include <iostream>

int main() {

	// PART C)
	ShapeFactory* console{ new ConsoleShapeFactory };

	auto pl{ console->CreatePolyline()};
	std::cout << "created: " << *pl << std::endl;
	// => everything works as expected


}