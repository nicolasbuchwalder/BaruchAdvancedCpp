// Level4_Section2_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>


using Vector = std::vector<double>;

int main() {

	// PART A, B

	std::chrono::steady_clock::time_point start, end;
	bool isSorted{true};

	Vector vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered

	// is_sorted_until standard
	start = std::chrono::steady_clock::now();
	isSorted = (vec8.end() == std::is_sorted_until(vec8.begin(), vec8.end()));
	end = std::chrono::steady_clock::now();
	std::cout << "is_sorted_until standard : is sorted? " << std::boolalpha << isSorted
		<< ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count() << "ns" << std::endl;

	// is_sorted_until with custom comparitor (descending order)
	start = std::chrono::steady_clock::now();
	isSorted = (vec8.end() == std::is_sorted_until(vec8.begin(), vec8.end(), [](double a, double b) {return a > b; }));
	end = std::chrono::steady_clock::now();
	std::cout << "is_sorted_until descending order : is sorted? " << std::boolalpha << isSorted
		<< ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count() << "ns" << std::endl;

	// is_sorted standard
	start = std::chrono::steady_clock::now();
	isSorted = std::is_sorted(vec8.begin(), vec8.end());
	end = std::chrono::steady_clock::now();
	std::cout << "is_sorted standard : is sorted? " << std::boolalpha << isSorted
		<< ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count() << "ns" << std::endl;

	// is_sorted with custom comparitor (descending order)
	start = std::chrono::steady_clock::now();
	isSorted = std::is_sorted(vec8.begin(), vec8.end(), [](double a, double b) {return a > b; });
	end = std::chrono::steady_clock::now();
	std::cout << "is_sorted descending order : is sorted? " << std::boolalpha << isSorted
		<< ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count() << "ns" << std::endl;

	//=> is_sorted is faster, which could make sense as the algorithm does not need to check exaclty when sorting fails
	//=> (as is_sorted_until) but only checks if it is sorted
}