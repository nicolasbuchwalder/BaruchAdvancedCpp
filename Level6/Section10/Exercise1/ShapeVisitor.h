// ShapeVisitor.h: Abstract class for changing shape
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

// forward declaration of shapes
class Point;
class Circle;
class Line;

class ShapeVisitor
{
public:
	
	// pure virtual functions for all types of shapes
	virtual void Visit(Point& p) = 0;
	virtual void Visit(Line& l) = 0;
	virtual void Visit(Circle& c) = 0;
	
};

