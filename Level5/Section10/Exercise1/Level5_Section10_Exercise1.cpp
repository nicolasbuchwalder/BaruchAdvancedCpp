// Level5_Section10_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#define BOOST_TYPEOF_EMULATION 

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <algorithm>



int main() {

	// PART A)
	 
	boost::numeric::ublas::vector<double> v1(3,1);
	v1[1] = 2; v1(2) = 3;
	std::cout << v1 << std::endl;


	// PART B)
	
	boost::numeric::ublas::vector<double> v2(3, 2);

	std::cout << (v1 += v2) << std::endl;
	std::cout << (v1 *= 2.5) << std::endl;
	std::cout << (v1 -= v2) << std::endl;


	// PART C)

	boost::numeric::ublas::vector<double> v3(3, 0);

	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::multiplies<double>());

	std::cout << v3 << std::endl;

	// PART D)

	boost::numeric::ublas::scalar_vector<double> v4(100, 5.0);

	std::cout << v4 << std::endl;
	
}