// Level6_Section10_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include "PrintVisitor.h"

#include <iostream>

int main() {

	PrintVisitor printer;

	Point p{ 1.0, 1.0 };
	printer.Visit(p);

	Line l{ Point(), p };
	printer.Visit(l);

	Circle c{ p, 1.0 };
	printer.Visit(c);

	// => printing works
}