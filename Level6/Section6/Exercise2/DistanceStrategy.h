// DistanceStrategy.h: Abstract class for different ways to calculate distance of points
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

// PART A)

// forward delcaration of point class
class Point;

class DistanceStrategy
{
public:
	// pure virtual function to calculate the distance
	virtual double Distance(const Point& p1, const Point& p2) = 0;
};

