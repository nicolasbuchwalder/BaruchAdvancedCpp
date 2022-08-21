// Level5_Section2-3_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <regex>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main() {

	// PART A)

	std::regex myReg10("/");
	std::string S3 = "2016/3/15";

	// putting the three ints in a vector  
	std::vector<std::string> dateInts; 

	// adding -1 to get the inverse of regex 
	auto begin_it = std::sregex_token_iterator(S3.begin(), S3.end(), myReg10, -1);
	auto end_it = std::sregex_token_iterator();

	for (auto it{ begin_it }; it != end_it; ++it) {
		dateInts.push_back(*it);
	}

	for (auto& elem : dateInts) { std::cout << elem << " "; };

	// getting seperators

	std::vector<std::string> seps;

	auto begin_it = std::sregex_token_iterator(S3.begin(), S3.end(), myReg10);
	auto end_it = std::sregex_token_iterator();

	for (auto it{ begin_it }; it != end_it; ++it) {
		seps.push_back(*it);
	}

	for (auto& elem : seps) { std::cout << elem << " "; };

	// PART C)

	boost::gregorian::date date{ boost::gregorian::date_from_iso_string(S3) };
	
}

