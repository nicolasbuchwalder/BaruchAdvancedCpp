#pragma once

#include "Point.h"
#include "Singleton.h"

class OriginPoint :
	public Singleton<Point>
{
};

//public:
//	OriginPoint() {};
//
//	// declaring copy and assign constructors that cannot be used as deleted
//	OriginPoint(const OriginPoint& copy) = delete;
//	OriginPoint& operator=(const OriginPoint& copy) = delete; 