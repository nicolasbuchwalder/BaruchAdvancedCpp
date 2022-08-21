// Level7_Exercise5.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Shape.h"
// PART B: see changes to point
#include "Point.h"
#include "OriginPoint.h"

// PART A,B)
#include "NewDistanceStrategy.h"

#include <functional>
#include <iostream>

// function for exact distance
double ExactDistance(const Point& p1, const Point& p2) {
	double delta_x = p1.x() - p2.x();
	double delta_y = p1.y() - p2.y();
	return std::sqrt(delta_x * delta_x + delta_y * delta_y);
}
// function for approximate distance
double ApproximateDistance(const Point& p1, const Point& p2) {
	return std::abs(p1.x() - p2.x()) + std::abs(p1.y() - p2.y());
};


int main() {

	// function wrappers to both distance strategies
	std::function<double(const Point& p1, const Point& p2)> exact = ExactDistance;
	std::function<double(const Point& p1, const Point& p2)> approx = ApproximateDistance;

	NewDistanceStrategy* exactStrat{ new NewDistanceStrategy(exact) };
	NewDistanceStrategy* approxStrat{ new NewDistanceStrategy(approx) };

	Point p1{ 0,0 };
	Point p2{ 1,1 };

	
	std::cout << "points: " << p1 << ", " << p2 << std::endl;

	Point::setStrategy(exactStrat);

	std::cout << "exact distance: " << p1.Distance(p2) << std::endl;
	std::cout << "exact distance (stateless): " << p1.Distance(p2, exactStrat) << std::endl;

	Point::setStrategy(approxStrat);

	std::cout << "approximate distance: " << p1.Distance(p2) << std::endl;
	std::cout << "approximate distance (stateless): " << p1.Distance(p2, approxStrat) << std::endl;
	//=> distance has indeed changed


	// PART C)
	std::cout << "exact distance called: " << exactStrat->GetNumCalls() << " times" << std::endl;
	std::cout << "approx distance called: " << exactStrat->GetNumCalls() << " times" << std::endl;
	// => we have indeed that both have been called twice

}