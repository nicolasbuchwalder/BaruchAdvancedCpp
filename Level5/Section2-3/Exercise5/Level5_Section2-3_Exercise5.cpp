// Level5_Section2-3_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <regex>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>


// function to print map
void print(const std::map<std::string, int>& map) {
	std::cout << "{";
	for (auto& elem : map) {
		std::cout << elem.first << "=" << elem.second << ", ";
	}
	std::cout << "}" << std::endl;
}

int main() {

	// PART A)

	std::string sA("a = 1, b = 2, c = 3");

	// regular expression defined by delimiter ","
	std::regex sep(", ?");

	std::vector<std::string> keyValuePairs;

	auto begin_it = std::sregex_token_iterator(sA.begin(), sA.end(), sep, -1);
	auto end_it = std::sregex_token_iterator();

	for (auto it{ begin_it }; it != end_it; ++it) {
		keyValuePairs.push_back(*it);
	}

	// PART B)

	std::map<std::string, int> map;

	// iterating over all key and value pairs strings
	for (auto& pair : keyValuePairs) {
		std::vector<std::string> keyValue;
		// splitting key and value into a vector (size 2)
		boost::split(keyValue, pair, boost::is_any_of("="));
		// adding trimmed elements to the map
		map[boost::trim_copy(keyValue[0])] = boost::lexical_cast<int>(boost::trim_copy(keyValue[1]));
	};
	
	print(map);
	// => works as expected

}