// Level5_Section2-3_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <set>
#include <regex>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

int main() {

	// GIVEN CODE
	std::string S2 = "1,1,2,3,5,8,13,21";
	std::regex myReg("(\\d+),?");

	// PART A)

	// regex iterator based on S2 and myReg
	auto it_begin = std::sregex_iterator(S2.begin(), S2.end(), myReg);
	auto it_end = std::sregex_iterator();

	// PART B)

	// set where values will be in
	std::set<std::string> setStr;

	// iterating over  regex iterator
	for (auto it{ it_begin }; it != it_end; ++it) {

		// dereferencing
		std::smatch match{ *it };
		// adding to output
		setStr.insert(match.str());
	}

	// PART C)

	for (auto& elem : setStr) { std::cout << elem << " "; }
	//=> we have indeed all unique values, but we have the commas in the strings, not great

	std::cout << std::endl;

	// PART D)

	// set where values will be in
	std::set<int> setInt;

	// iterating over  regex iterator
	for (auto it{ it_begin }; it != it_end; ++it) {

		// dereferencing
		std::smatch match{ *it };


		// getting int from string
		int value{ boost::lexical_cast<int>(boost::trim_copy_if(match.str(), boost::is_any_of(" ,"))) };

		// adding to output
		setInt.insert(value);
	};

	for (auto& elem : setInt) { std::cout << elem << " "; }
	//=> we have indeed all unique values, but now as ints, which also helps getting the numbers ordered




}