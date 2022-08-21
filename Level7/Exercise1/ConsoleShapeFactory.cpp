#include "ConsoleShapeFactory.h"

#include "Point.h"
#include "Line.h"
#include "Circle.h"

// function to create point
std::shared_ptr<Point> ConsoleShapeFactory::CreatePoint() {
	double x, y;
	std::cout << "Creating Point:\n\tenter x: ";
	std::cin >> x;
	std::cout << "\tenter y: ";
	std::cin >> y;
	return std::make_shared<Point>(x, y);

};

// function to create line
std::shared_ptr<Line> ConsoleShapeFactory::CreateLine() {
	double x1, y1, x2, y2;
	std::cout << "Creating Line:\n \tenter x1: ";
	std::cin >> x1;
	std::cout << "\tenter y1: ";
	std::cin >> y1;
	std::cout << "\tenter x2: ";
	std::cin >> x2;
	std::cout << "\tenter y2: ";
	std::cin >> y2;
	return std::make_shared<Line>(Point(x1, y1), Point(x2, y2));
};

// function to create circle
std::shared_ptr<Circle> ConsoleShapeFactory::CreateCircle() {
	double x, y, r;
	std::cout << "Creating Circle:\n \tenter x: ";
	std::cin >> x;
	std::cout << "\tenter y: ";
	std::cin >> y;
	std::cout << "\tenter r: ";
	std::cin >> r;
	return std::make_shared<Circle>(Point(x, y), r);
};

std::tuple<std::shared_ptr<Point>, std::shared_ptr<Line>, std::shared_ptr<Circle>> ConsoleShapeFactory::CreateShapes() {
	return std::make_tuple(CreatePoint(), CreateLine(), CreateCircle());
}