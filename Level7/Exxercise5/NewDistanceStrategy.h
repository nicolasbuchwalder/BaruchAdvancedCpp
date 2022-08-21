// NewDistanceStrategy.h: New class for different ways to calculate distance of points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course#pragma once

#include <functional>

// forward delcaration of point class
class Point;

class NewDistanceStrategy
{
private:
	// wrapper to the function that will compute the distance
	std::function<double(const Point& p1, const Point& p2)> _strategy;
	
	// PART C)
	// counter for number of calls
	int _counter{0};

public:
	// constructor
	NewDistanceStrategy(std::function<double(const Point& p1, const Point& p2)> strategy) :
		_strategy{ strategy } {};

	// member function used in the Point method
	double Distance(const Point& p1, const Point& p2) {
		// PART C)
		++_counter;
		return _strategy(p1, p2);
	}

	// PART C)

	// function to get the number of calls
	int GetNumCalls() {
		return _counter;
	}
};

