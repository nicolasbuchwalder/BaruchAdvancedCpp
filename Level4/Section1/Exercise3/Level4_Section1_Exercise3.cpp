// Level4_Section1_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Matrix.h"

#include <iostream>
#include <array>
#include <complex>

int main() {
	Matrix<double, 2, 2> m1(5);
	std::cout << m1 << std::endl;
	Matrix<double, 2, 2> m2(-2);
	std::cout << m2 << std::endl;

	// checking that implemented functions work
	Matrix<double, 2, 2> m3(m1);
	std::cout << m1 + m2 << std::endl;
	std::cout << m1 - m2 << std::endl;

	double pi{ 3.14 };
	std::cout << pi * m1 << std::endl;
	std::cout << std::endl;
	//=> everything seems to work fine



	// creating lambda function that will modify the values of the array
	std::function<double(double)> squared = [](double i) {return std::cos(i); };
	std::cout << "Original matrix:" << std::endl << m1 << std::endl;
	m1.modify(squared);
	std::cout << "Modified matrix:" << std::endl << m1 << std::endl;
	//=> works
};

