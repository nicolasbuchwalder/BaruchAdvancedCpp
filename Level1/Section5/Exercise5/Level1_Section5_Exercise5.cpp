// Level1_Section5_Exercise5.cpp: This file contains the main function for this exercise. @Nicolas Buchwalder


#include "Shape.h"
#include "IODevice.h"

// PART A)
// see all 4 headers below for part a)
#include "Circle.h"
#include "Line.h"

#include "IODevice1.h"
#include "IODevice2.h"

// PART B)
// see all 5 headers below for part b)
#include "Builder.h"
#include "Builder1.h"
#include "Builder2.h"
#include "Builder3.h"
#include "Builder4.h"


#include <iostream>
#include <tuple>

// aliases for the shared pointers and their tuple
using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;
using DisplayTuple = std::tuple<ShapePointer, IODevicePointer>;

int main() {
	Builder1 b1;
	DisplayTuple d1{ b1.getProduct() };
	(*std::get<0>(d1)).display(*std::get<1>(d1));
	//=> we get a circle on device 1 as expected

	Builder2 b2;
	DisplayTuple d2{ b2.getProduct() };
	(*std::get<0>(d2)).display(*std::get<1>(d2));
	//=> we get a circle on device 2 as expected

	Builder3 b3;
	DisplayTuple d3{ b3.getProduct() };
	(*std::get<0>(d3)).display(*std::get<1>(d3));
	//=> we get a line on device 1 as expected

	Builder4 b4;
	DisplayTuple d4{ b4.getProduct() };
	(*std::get<0>(d4)).display(*std::get<1>(d4));
	//=> we get a line on device 2 as expected


}