// Level5_Section10_Exercise7.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#define BOOST_TYPEOF_EMULATION

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>

int main() {
	
	boost::numeric::ublas::vector<double> vec1(3);
	vec1(0) = 1; vec1(1) = 2; vec1(2) = 3;

	boost::numeric::ublas::vector<double> vec2(3);
	vec2(0) = 2; vec2(1) = 3; vec2(2) = 1;

	// inner product of two vectors
	std::cout << boost::numeric::ublas::inner_prod(vec1, vec2) << std::endl;

	// outer product of two vectors
	std::cout << boost::numeric::ublas::outer_prod(vec1, vec2) << std::endl;

	// adding two vectors
	std::cout << vec1 + vec2 << std::endl;

	// substracting two vectors
	std::cout << vec1 - vec2 << std::endl;

	// euclidian norm of a vector
	std::cout << boost::numeric::ublas::norm_2(vec1) << std::endl;

	// L1 norm of a vector
	std::cout << boost::numeric::ublas::norm_1(vec1) << std::endl;

	// max norm of a vector
	std::cout << boost::numeric::ublas::norm_inf(vec1) << std::endl;


	boost::numeric::ublas::matrix<double> m = boost::numeric::ublas::outer_prod(vec1, vec2);

	// L1 norm of a matrix
	std::cout << boost::numeric::ublas::norm_1(m) << std::endl;

	// max norm of a matrix
	std::cout << boost::numeric::ublas::norm_inf(m) << std::endl;

	// product of matrix and vector
	std::cout << boost::numeric::ublas::prod(m, vec1) << std::endl;




}