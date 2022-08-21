// Level4_Section3_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <random>
#include <boost/random.hpp>
#include <boost/random/generate_canonical.hpp>
#include <iostream>



int main() {
	
	// PART A)

	// triangle distribution with lagged fibonacci
	std::random_device rd;
	boost::lagged_fibonacci1279 eng(rd());
	boost::triangle_distribution<> dist;
	boost::variate_generator<boost::random::lagged_fibonacci1279, boost::random::triangle_distribution<>> gen(eng, dist);

	std::cout << gen() << std::endl;

	// PART B)
	
	std::cout << boost::random::generate_canonical<float, 8>(eng) << std::endl;
	std::cout << boost::random::generate_canonical<float, 16>(eng) << std::endl;
	std::cout << boost::random::generate_canonical<float, 32>(eng) << std::endl;
	//=> very small results: why?


}