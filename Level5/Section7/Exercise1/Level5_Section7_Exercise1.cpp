// Level5_Section7_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/bimap.hpp>
#include <string>
#include <iostream>

using  bm_type = boost::bimap<std::string, int>;
using  input_type = bm_type::value_type;


int main() {

	// PART A)

	// populating bimap
	bm_type bm;
	bm.insert(input_type("Alice", 21));
	bm.insert(input_type("Bob", 32));
	bm.insert(input_type("Charlie", 43));

	//bm.emplace(input_type("Charlie", 43))
	// => emplace doesnt work

	// PART B)

	// priting from left view
	std::cout << "left map: ";
	for (auto it = bm.left.begin(); it != bm.left.end(); ++it) {
		std::cout << it->first << " : " << it->second << ", ";
	}
	std::cout << std::endl;

	// printing from right view
	std::cout << "right map: ";
	for (auto it = bm.right.begin(); it != bm.right.end(); ++it) {
		std::cout << it->first << " : " << it->second << ", ";
	}
	std::cout << std::endl;

	// PART C)

	std::string searchName{ "Bob" };
	try { std::cout << "age of " << searchName << " is: " << bm.left.at(searchName) << std::endl; }
	catch (...) { std::cout << "'" << searchName << "' is not on left map" << std::endl; }

	int searchAge{ 7 };
	try { std::cout << "name of " << searchAge << " is: " << bm.right.at(searchAge) << std::endl; }
	catch (...) { std::cout << "'" << searchAge << "' is not on right map" << std::endl; }


	// PART D)

	// priting from relation view
	std::cout << "relation map: ";
	for (auto it = bm.begin(); it != bm.end(); ++it) {
		std::cout << it->left << " : " << it->right << ", ";
	}
	std::cout << std::endl;


}