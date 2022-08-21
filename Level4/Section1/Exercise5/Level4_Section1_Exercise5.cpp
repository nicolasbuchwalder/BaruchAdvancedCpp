// Level4_Section1_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Vector.h"
#include "Matrix.h"

#include <array>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <complex>

// PART A)

// function that computes inner product of two vectors
template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue) {
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue);
};

template <typename T>using BinaryFunction = std::function < T(const T& t1, const T& t2)>;

template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue, const BinaryFunction<T>& op1, const BinaryFunction<T>& op2) {
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue, op1, op2);
};

// PART D)

// function that o=computes outer product of two vectors
template <typename T, int N>
Matrix<T, N, N> outer_product(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	Matrix<T, N, N> res;
	int row{ 0 };
	// iterating over the first vector: the ith element will be in the ith row
	std::for_each(v1.begin(), v1.end(), [&](T value) {
		// storing ith row in res, by multipling the second vector by the ith element of first vector
		std::transform(v2.begin(), v2.end(), res[row].begin(), [value](T value2) {return std::multiplies<T>()(value, value2); });
		++row;
	});
	return res;

};


int main() {

	// PART B)

	Vector<double, 4> vec = std::array<double, 4>{1, 2, 3, 4};
	std::cout << inner_product(vec, vec, 0.0) << std::endl;
	//=> works as expected

	// PART C)
	
	// add binary function
	BinaryFunction<double> ADD = [](const double& t1, const double& t2) {return t1 + t2; };

	// multiply binary function
	BinaryFunction<double> MUL = [](const double& t1, const double& t2) {return t1 * t2; };

	std::cout << "add, add: " << inner_product(vec, vec, 0.0, ADD, ADD) << std::endl;
	std::cout << "add, mul: " << inner_product(vec, vec, 0.0, ADD, MUL) << std::endl;
	std::cout << "mul, add: " << inner_product(vec, vec, 0.0, MUL, ADD) << std::endl;
	std::cout << "mul, mul: " << inner_product(vec, vec, 0.0, MUL, MUL) << std::endl;


	// PART D)

	Matrix<double, 4,4> opres{ outer_product(vec, vec) };
	std::cout << opres << std::endl;
	//=> also works as expected

	// PART E)

	Vector<std::complex<double>, 3> complexVec = std::array<std::complex<double>, 3>{(1, 0), (0, 1), (1, 1)};
	Matrix<std::complex<double>, 3, 3> opcomplexres{ outer_product(complexVec, complexVec) };
	std::cout << opcomplexres << std::endl;
	// => works as well
	

}