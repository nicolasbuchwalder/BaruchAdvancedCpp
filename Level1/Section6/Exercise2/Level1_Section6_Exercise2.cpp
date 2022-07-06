// Level1_Section6_Exercise2.cpp: This file contains the main function for this exercise. @Nicolas Buchwalder

#include "TMPClass.h"

#include <vector>
#include <iostream>

using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

int main() {
	std::vector<double> vec(10);
	double startValue{1.0};
	
	// Setting input and output functions
	// in function is just a constant value
	double inValue{ 3.14 };
	InputFunction in_function = [=]() {return inValue; };
	// out function is just printing each element of the vector
	OutputFunction out_function = [](const std::vector<double>& in_vec) { 
		for (auto elem : in_vec) { std::cout << elem << ", "; }; 
		std::cout << std::endl;
	};

	std::size_t n{ 10 };
	TMPClass algo(n, startValue, in_function, out_function);
	algo.out();
	// we got indeed 3.14 for a vector of 10 values, works proprely
}