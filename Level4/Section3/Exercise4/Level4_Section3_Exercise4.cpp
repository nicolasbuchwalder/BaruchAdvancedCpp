// Level4_Section3_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <random>
#include <cmath>
#include <iostream>

int main() {

	// PART A)

	// engine and seed
	std::random_device rd;
	std::mt19937 gen{ rd() };
	
	// PART B)

	//two instances on the unit interval
	std::uniform_real_distribution<double> dist_x(0, 1);
	std::uniform_real_distribution<double> dist_y(0, 1);

	// PART C, D)

	int N{ 0 };
	int counter{ 0 };
	// looping for different number of trials (in powers of 10)
	for (int i{ 0 }; i < 10; ++i) {
		N = std::pow( 10, i);
		counter = 0;
		// generating x and y randomly
		for (int j{ 0 }; j < N; ++j) {
			double x{ dist_x(gen) };
			double y{ dist_y(gen) };
			// adding to counter if larger than 1
			if (std::sqrt(x * x + y * y) < 1) { ++counter; };
		}
		std::cout << "For N = " << N << ": pi = " << 4 * counter /(double) N << std::endl;

	}
	//=> we need about 10^9 times to get to the right result

}