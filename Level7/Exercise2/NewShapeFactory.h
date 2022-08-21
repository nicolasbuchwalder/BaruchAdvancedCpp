// NewShapeFactory.h: Single class to handle all kinds of factories
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
#include <memory>
#include <functional>

// forward declaration of classes
class Point;
class Line;
class Circle;

// alias definition for readibility
template <typename T>
using creator = std::function<std::shared_ptr<T>()>;

class NewShapeFactory
{

private:
	// private data members used to 
	creator<Point> _create_point;
	creator<Line> _create_line;
	creator<Circle> _create_circle;

public:

	// constructor which gets the functions
	NewShapeFactory(const creator<Point>& point_func,
		const creator<Line>& line_func,
		const creator<Circle>& circle_func) :
		_create_point{ point_func }, _create_line{ line_func }, _create_circle{ circle_func }{};

	// function to change the way the factory build them
	void AssignPointCreator(creator<Point> point_func) {
		_create_point = point_func;
	}
	void AssignLineCreator(creator<Line> line_func) {
		_create_line = line_func;
	}
	void AssignCircleCreator(const creator<Circle>& circle_func) {
		_create_circle = circle_func;
	}

	// methods to create all three shapes based on the function members
	std::shared_ptr<Point> CreatePoint() {
		return _create_point();
	};
	std::shared_ptr<Line> CreateLine() {
		return _create_line();
	};
	std::shared_ptr<Circle> CreateCircle() {
		return _create_circle();
	};

};