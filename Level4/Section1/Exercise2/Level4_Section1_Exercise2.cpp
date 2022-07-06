// Level4_Section1_Exercise2.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Vector.h"

#include <iostream>
#include <array>
#include <complex>

int main() {
	// PART B)
	Vector<double, 3> vec1(std::array<double, 3>{1, 2, 3});
	std::cout << vec1 << std::endl;
	Vector<double, 3> vec2(std::array<double, 3>{4, 5, 6});
	std::cout << vec2 << std::endl;

	// PART C)
	// checking that implemented functions work
	Vector<double, 3> vec3(vec1);
	std::cout << vec1 + vec2 << std::endl;
	std::cout << vec1 - vec2 << std::endl;
	std::cout << -vec1 << std::endl;
	//double pi{ 3.14 };
	//std::cout << pi * vec1 << std::endl;
	std::cout << std::endl;
	//=> everything seems to work fine

	// PART D)
	// checking that the scalar multiplication works
	Vector<std::complex<double>, 2> cmpvec1(std::array<std::complex<double>,2>{std::complex<double>(1, 0), std::complex<double>(0, 1)});
	//std::cout << 3.14 * vec1 << std::endl;
	//=> works indeed with any type


	// PART E)
	// creating lambda function that will modify the values of the array
	std::function<double(double)> squared = [](double i) {return i * i; };
	std::cout << "Original vector:" << vec1 << std::endl;
	//vec1.modify(squared);
	//std::cout << "Modified vector:" << vec1 << std::endl;
};

