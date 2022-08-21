// Level5_Section1_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <map>
#include <vector>

// PART B)

// function that converts strings with YYYY-MM-DD format into boost date
boost::gregorian::date parse_date(const std::string& s) {
	return boost::gregorian::from_simple_string(s);
}

// PART C)

// function that converts strings maps to maps
std::map<std::string, double> parse_map(const std::string& s) {

	// creating non const copy
	std::string copy{ s };

	// trimming spaces
	boost::erase_all(copy, " ");

	// splitting keys and values
	std::vector<std::string> splits;
	boost::split(splits, copy, boost::is_any_of(",="));

	// construting map
	std::map<std::string, double> out;
	for (int i{ 0 }; i < splits.size(); i += 2) {
		out[splits[i]] = boost::lexical_cast<double>(splits[i + 1]);
	};

	return out;
}

// function to print map
void print(const std::map<std::string, double>& map) {
	std::cout << "{";
	for (auto& elem : map) {
		std::cout << elem.first << "=" << elem.second << ", ";
	}
	std::cout << "}" << std::endl;
}


int main() {

	// PART A)

	std::string  sA("1,2,3,4/5/9*56");
	std::vector<std::string> splits;

	// splitting string into vec of strings
	boost::split(splits, sA, boost::is_any_of("/,*"));
	for (auto& elem : splits) { std::cout << elem << "-"; };
	std::cout << std::endl;

	//joining vector into unique string
	std::string joined{ boost::join(splits, "/") };
	std::cout << joined << std::endl;


	// PART B)

	std::string dateStr{ "2015-12-31" };
	auto date{parse_date(dateStr)};
	std::cout << date << std::endl;

	// PART C)

	std::string mapStr{ "port = 23, pin = 87, value = 34.4" };
	print(parse_map(mapStr));
}
