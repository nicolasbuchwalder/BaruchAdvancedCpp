// ConsoleShapeFactory.h:  Class for interactive shape creating through console
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include "ShapeFactory.h"


#include <iostream>

class ConsoleShapeFactory :
    public ShapeFactory
{
public:

	// function to create point
	std::shared_ptr<Point> CreatePoint();

	// function to create circle
	std::shared_ptr<Circle> CreateCircle();
};

