// ShapeFactory.cpp: Base class for interactive shape creating
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "ShapeFactory.h"

#include "Line.h"
#include "Polyline.h"

#include <iostream>

// PART A)

// function to create line, USING CREATEPOINT
std::shared_ptr<Line> ShapeFactory::CreateLine() {
	double x1, y1, x2, y2;
	std::cout << "Creating Line, using CreatePoint for start and end:\n";
	std::shared_ptr<Point> p1{ CreatePoint() };
	std::shared_ptr<Point> p2{ CreatePoint() };
	return std::make_shared<Line>(*p1, *p2);
};

// PART B)

// creating polyline USING CREATEPOINT
std::shared_ptr<Polyline> ShapeFactory::CreatePolyline() {
	int size;
	std::cout << "Creating Polyline, using CreatePoint for all points.\nEnter number of points:";
	std::cin >> size;
	std::vector<std::shared_ptr<Point>> points;
	for (int i{ 0 }; i < size; ++i) { points.push_back(CreatePoint()); };
	return std::make_shared<Polyline>(Polyline(points));
};