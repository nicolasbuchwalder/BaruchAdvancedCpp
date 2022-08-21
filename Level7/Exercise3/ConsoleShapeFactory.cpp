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