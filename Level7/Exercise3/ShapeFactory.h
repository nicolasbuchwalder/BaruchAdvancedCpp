// ShapeFactory.h: Base class for interactive shape creating
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
#include <memory>
#include <vector>

// forward declaration of classes
class Point;
class Line;
class Circle;
class Polyline;


class ShapeFactory
{
public:
	// Pure virtual functions to create point, line and circles
	virtual std::shared_ptr<Point> CreatePoint() = 0;
	virtual std::shared_ptr<Circle> CreateCircle() = 0;

	// PART A)
	
	// creating line should not be abstract any more as it relies on how to create points
	virtual std::shared_ptr<Line> CreateLine() final;

	// PART B)

	// creating polyline that relies on how to create points
	virtual std::shared_ptr<Polyline> CreatePolyline() final;

};

