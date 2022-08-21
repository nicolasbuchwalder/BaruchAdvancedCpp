// Level5_Section4-6_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <functional>
#include <boost/functional/hash.hpp>
#include <string>
#include <limits>
#include <iostream>

// PART A)

// std function template to hash data type
template <typename T>
std::size_t stdHashtable(T key) {
	return std::hash<T>()(key);
}

// std function template to hash data type
template <typename T>
std::size_t boostHashtable(T key) {
	return boost::hash<T>()(key);
}


int main() {

	// PART B)

	int int_var{ 1 };
	double double_var{ 3.14 };
	long long_var{ std::numeric_limits<long>::max() };
	std::string string_var{ "hello" };
	std::string* string_pointer_var{ &string_var };

	std::cout << "std for int: " << stdHashtable(int_var) << std::endl;
	std::cout << "boost for int: " << boostHashtable(int_var) << std::endl;

	std::cout << "std for double: " << stdHashtable(double_var) << std::endl;
	std::cout << "boost for double: " << boostHashtable(double_var) << std::endl;

	std::cout << "std for long: " << stdHashtable(long_var) << std::endl;
	std::cout << "boost for long: " << boostHashtable(long_var) << std::endl;

	std::cout << "std for string: " << stdHashtable(string_var) << std::endl;
	std::cout << "boost for string: " << boostHashtable(string_var) << std::endl;

	std::cout << "std for string pointer: " << stdHashtable(string_pointer_var) << std::endl;
	std::cout << "boost for string pointer: " << boostHashtable(string_pointer_var) << std::endl;

	// PART B)

	std::string string_var2{ "world" };
	// creating hashs
	auto h1{ stdHashtable(string_var) };
	auto h2{ stdHashtable(string_var2) };

	// doing the wanted computation
	std::cout << "h1 ^ (h2 << 1): " << (h1 ^ (h2 << 1)) << std::endl;



}