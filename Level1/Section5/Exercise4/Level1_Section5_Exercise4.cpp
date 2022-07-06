// Level1_Section5_Exercise4.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <random>

// PART A)
// template with struct and static method to find the best matching index where values are between x
template <typename T, typename X_t,  typename Vec, std::size_t N>
struct Finder {
	static int best_index(const Vec& v, X_t x) {
		// checking if target value is in the range
		if ((v[0] > x) || v[N-1] < x) {
			std::cout << "Target value is not in the range of the vector" << std::endl; 
			return -1;
		}
		else {
			// as the vector is sorted, we know that if the next value of the vector is bigger than x, then we found the interval
			for (int i{ 1 }; i < N; ++i) {
				if (v[i] > x) { return i - 1; };
			};
		};
	};
};

// PART B)
// types of error
enum ErrorTypes {
	absoluteerror, relativeerror, absoluterelativeerror
};


template <typename T, typename Vec, std::size_t N>
struct CompareVector {
	static std::tuple<T, int> max_error(const Vec& v1, const Vec& v2, int i, int j, ErrorTypes errortype) {
		if ((i < 0) || (i > j) || (j > N)) {
			std::cout << "Range must be coherent with vector size, i should be smaller than j" << std::endl;
			return std::make_tuple(-1, -1);
		}
		else {
			std::vector<T> error;

			for (int k{ i }; k <= j; ++k) {
				// if the value is zero, then relative errors are undefined
				if (v1[k] != 0) {
					// computing errors in function of the errortype
					switch (errortype) {
					case absoluteerror: error.push_back(std::abs(v2[k] - v1[k])); break;
					case relativeerror: error.push_back((v2[k] - v1[k]) / v1[k]); break;
					case absoluterelativeerror: error.push_back(std::abs(v2[k] - v1[k]) / v1[k]); break;
					};
				}
				else {
					// computing errors in function of the errortype
					switch (errortype) {
					case absoluteerror: error.push_back(std::abs(v2[k] - v1[k])); break;
					case relativeerror: error.push_back(-1); break;
					case absoluterelativeerror: error.push_back(-1); break;
					};
				};
				
			};
			// finding max element
			auto maxIdx{ std::max_element(error.begin(), error.end()) };
			// returning max error and index in the whole vector (so + i)
			return std::make_tuple(*maxIdx, maxIdx - error.begin() + i);
		};

	};
};

int main() {
	// PART A)
	std::vector<int> vec(10);
	for (int i{ 0 }; i < 10; ++i) { vec[i] = i; };
	std::cout << "Vector: ";
	for (auto val : vec) { std::cout << val << ", "; };
	std::cout << std::endl;
	double x{ 3.14 };
	std::cout << "Finding value: " << x << std::endl;
	std::cout << "Best Index: " << Finder<int, double, std::vector<int>, 10>::best_index(vec, x) << std::endl;

	// PART B)
	std::vector<double> vec2(10);
	for (int i{ 0 }; i < 10; ++i) { vec2[i] = ((7 * i) % 10 - 2.7) * 2.1; };
	std::cout << "Vector 1: ";
	for (auto val : vec2) { std::cout << val << ", "; };
	std::cout << std::endl;
	std::vector<double> vec3(10);
	for (int i{ 0 }; i < 10; ++i) { vec3[i] = ((7 * i) % 10 + 1.3) * 1.7; };
	std::cout << "Vector 2: ";
	for (auto val : vec3) { std::cout << val << ", "; };
	std::cout << std::endl;

	auto res1{ CompareVector<double, std::vector<double>, 10>::max_error(vec2, vec3, 2, 8, ErrorTypes::absoluteerror) };
	std::cout << "Absolute Error: index: " << std::get<1>(res1) << ", value: " << std::get<0>(res1) << std::endl;

	auto res2{ CompareVector<double, std::vector<double>, 10>::max_error(vec2, vec3, 2, 8, ErrorTypes::relativeerror) };
	std::cout << "Relative Error: index: " << std::get<1>(res2) << ", value: " << std::get<0>(res2) << std::endl;

	//=> we notice that highest error are not identical, because one is absolute and the other is relative
}