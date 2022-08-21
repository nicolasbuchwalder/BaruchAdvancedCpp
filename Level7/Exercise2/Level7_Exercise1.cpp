// Level7_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

// PART A)
#include "NewShapeFactory.h"

#include "ConsoleShapeFactory.h"

#include <iostream>

int main() {

	// PART B, D)

	// lambda function for factory creation of Point
	creator<Point> lambda_point = []() {return std::make_shared<Point>(Point(1, 1)); };

	// function object for factory creation of Circle
	struct FO {
		std::shared_ptr<Line> operator()() {
			return std::make_shared<Line>(Line(Point(0, 0), Point(1, 1)));
		}
	};
	creator<Line> function_object_line = FO();

	// bind to the original code
	ConsoleShapeFactory* old_console_factory = new ConsoleShapeFactory;
	creator<Circle> bind_circle = std::bind(&ConsoleShapeFactory::CreateCircle, old_console_factory);

	NewShapeFactory* factory = new NewShapeFactory(lambda_point, function_object_line, bind_circle);

	// testing the methods
	
	std::cout << "point created:" << *(factory->CreatePoint()) << std::endl;
	std::cout << "line created:" << *(factory->CreateLine()) << std::endl;
	factory->CreateCircle();
	// => methods are indeed used

	factory->AssignPointCreator(std::bind(&ConsoleShapeFactory::CreatePoint, old_console_factory));
	factory->CreatePoint();
	// => assignment works as well

	// PART C)
	
	// For new types of shapes, only Factory class must be updated (instead of all other derived classes like ConsoleShapeFactory)
	// This seems easier to maintain and also more flexible
	// It is still maybe harder to really keep track of which methods correspond to which factory type


	


}