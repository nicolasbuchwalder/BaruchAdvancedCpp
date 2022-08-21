// Level5_Section10_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#define BOOST_TYPEOF_EMULATION 

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <boost/numeric/ublas/matrix_proxy.hpp>

int main() {

	// PART A)

	boost::numeric::ublas::matrix<int> m1(3, 3, 0);
	m1(0, 0) = 1; m1(1, 0) = 1; m1(2, 0) = 1;

	std::cout << "whole matrix: " << m1 << std::endl;

	boost::numeric::ublas::matrix_row<boost::numeric::ublas::matrix<int>> row(m1, 0);
	std::cout << "first row: " << row << std::endl;

	boost::numeric::ublas::matrix_column<boost::numeric::ublas::matrix<int>> col(m1, 1);
	std::cout << "second column: " << col << std::endl;

	boost::numeric::ublas::matrix_range<boost::numeric::ublas::matrix<int>> range(m1, boost::numeric::ublas::range(0,1), boost::numeric::ublas::range(0, 2));
	std::cout << "range 0-1 on x and range 0-2 on y: " << range << std::endl;

	boost::numeric::ublas::matrix_slice<boost::numeric::ublas::matrix<int>> slice(m1, boost::numeric::ublas::slice(0,1,1), boost::numeric::ublas::slice(0, 1,2));
	std::cout << "slive 0-1-1 on x and slive 0-1-2 on y: " << slice << std::endl;


	// PART B)

	boost::numeric::ublas::matrix<double> m2(3, 3, 0);
	boost::numeric::ublas::matrix_slice< boost::numeric::ublas::matrix<double> >ms(m2, boost::numeric::ublas::slice(0, 1, 3), boost::numeric::ublas::slice(0, 1, 3));
	std::cout << "part b: " << ms << std::endl;
}