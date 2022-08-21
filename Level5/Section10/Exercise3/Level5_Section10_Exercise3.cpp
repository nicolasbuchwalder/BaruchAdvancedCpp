// Level5_Section10_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#define BOOST_TYPEOF_EMULATION 

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <complex>
#include <iostream>

int main() {

	// PART A)

	boost::numeric::ublas::mapped_matrix<std::complex<double>> sm(3, 3);
	sm(0, 0) = (1, 1); sm(1, 1) = (1, 1); sm(2, 2) = (1, 1);
	std::cout << sm << std::endl;

	// PART B)

	boost::numeric::ublas::triangular_matrix<double, boost::numeric::ublas::upper> u(3, 3);
	for (int i = 0; i < u.size1(); ++i) {
		for (int j = i; j < u.size2(); ++j) {
			u(i, j) = (i==j) ? 1 : 0;
		}
	}
	std::cout << u << std::endl;

	boost::numeric::ublas::triangular_matrix<double, boost::numeric::ublas::lower> l(3, 3);
	for (int i = 0; i < l.size1(); ++i) {
		for (int j = 0; j <= i; ++j) {
			l(i, j) = (i == j) ? 1 : 0;
		}
	}
	std::cout << l << std::endl;

	// PART C)
	
	boost::numeric::ublas::matrix<double> dense(3, 3, 1);
	boost::numeric::ublas::triangular_adaptor<boost::numeric::ublas::matrix<double>, boost::numeric::ublas::lower> newl(dense);
	std::cout << newl << std::endl;
}