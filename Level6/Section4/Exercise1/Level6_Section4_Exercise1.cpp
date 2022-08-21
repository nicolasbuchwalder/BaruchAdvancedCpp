// Level6_Section4_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include "ShapeComposite.h"

#include <iostream>

// function that prints the shapes of a shapecomposite, not recursively
void PrintComposite(ShapeComposite& sc) {
	for (auto ptr : sc) {
		std::cout << *ptr << std::endl;
	}
}

int main() {

	Point p1{};
	Point p2{ 1.0, 1.0 };
	Point p3{ 2.0, 0.0 };
	Line l1{ p1, p2 };
	Line l2{ p1, p3 };
	Circle c1{ p2, 1.0 };

	ShapeComposite sc;
	sc.AddShape(std::make_shared<Point>(p1));
	sc.AddShape(std::make_shared<Point>(p2));
	sc.AddShape(std::make_shared<Point>(p3));
	sc.AddShape(std::make_shared<Line>(l1));
	sc.AddShape(std::make_shared<Line>(l2));
	sc.AddShape(std::make_shared<Circle>(c1));

	PrintComposite(sc);
	std::cout << "-----------" << std::endl;

	ShapeComposite sc2(sc);
	//=> now this works because copy constructor exists

	PrintComposite(sc2);
	//=> we have indeed the same elements
	

}