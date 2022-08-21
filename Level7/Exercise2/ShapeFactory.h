// ShapeFactory.h: Abstract class for interactive shape creating
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
#include <memory>
#include <tuple>

// forward declaration of classes
class Point;
class Line;
class Circle;


class ShapeFactory
{
public:
	// pure virtual functions to create point, line and circles
	virtual std::shared_ptr<Point> CreatePoint() = 0;
	virtual std::shared_ptr<Line> CreateLine() = 0;
	virtual std::shared_ptr<Circle> CreateCircle() = 0;

	// pure virtual function to create a tuple of points, line and circle
	virtual std::tuple<std::shared_ptr<Point>, std::shared_ptr<Line>, std::shared_ptr<Circle>> CreateShapes() = 0;
};



