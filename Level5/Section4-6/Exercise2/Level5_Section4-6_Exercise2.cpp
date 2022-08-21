// Level5_Section4-6_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART A)
#include "Point.h"
#include "LineSegment.h"

#include <list>
#include <boost/functional/hash.hpp>
#include <iostream>

// instead of creating a whole class to hash the Point clas, we will just add this template function object
template <>
struct boost::hash<Point> {
	std::size_t operator()(const Point& p) { return Point::hash(p); }
};

// same for LineSegment
template <>
struct boost::hash<LineSegment> {
	std::size_t operator()(const LineSegment& ls) { return LineSegment::hash(ls); }
};

// PART C)

struct PointHash: std::unary_function < Point, std::size_t>
{
	std::size_t operator() (const Point& pt) const
	{
		std::size_t seed = 0;
		boost::hash_combine(seed, pt.x());
		boost::hash_combine(seed, pt.y());
		return seed;
}
};

int main() {

	// PART A)
	std::list<Point> points;
	for (int i{ 0 }; i < 10; ++i) { points.push_back(Point(i % 3, i / 3)); };

	// PART B)
	auto hashList{ boost::hash_range(points.begin(), points.end()) };
	std::cout << "hash of points: " << hashList << std::endl;

	// PART C)
	PointHash customPointHash;
	std::size_t res{ customPointHash(points.front()) };
	std::cout << "custom hash of single point: " << res << std::endl;

}