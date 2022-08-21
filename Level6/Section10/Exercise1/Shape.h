// Shape.h: Abstract class for different shapes
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "ShapeVisitor.h"

#include <iostream>
#include <string>


class Shape
{
public:
	Shape() {};  // Default constructor
	Shape(const Shape& shp) {};  // Copy constructor
	Shape& operator=(const Shape& shp) {}; // Assignment operator 
	//=> abstract class cannot be instantiated, so constructors left blank

protected:
	// pure virtual function to print shape
	virtual std::string print() const = 0;
	
	// friend function to print class (which will be inherited for all derived classes)
	friend std::ostream& operator<<(std::ostream& out, const Shape& s) {
		return (out << s.print() << " ");
	}

	// pure virtual function to accept shape visitor 
	virtual void Accept(ShapeVisitor& visitor) = 0;
};

