// HashPoint.h: This file contains the HashPoint class that is used for hasing point
// so that Point can be used in an ordered set
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "Point.h"

#include <functional>

class HashPoint
{
public:
	// function that hashes point 
	std::size_t operator()(Point const& point) const noexcept{
		// we assume that points will be less than 100, so we can do this
		return std::hash<double>()(point.x()) + 100 * std::hash<double>()(point.y());
	}
};

