// Level5_Section2-3_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <regex>
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>

// PART C)

// function that tries to parse string as a double number
double str2double(const std::string& number) {

	static std::regex ecmaReg("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");

	// checking if parsable 
	if (std::regex_match(number, ecmaReg)) {
		double out{ boost::lexical_cast<double>(number) };
		std::cout << number << " has been converted to " << out << std::endl;
		return out;
	}
	else {
		std::cout << "error: " << number << " cannot be converted to double" << std::endl;
		return 0;
	}

}

int main() {

	// PART A)

	std::regex ecmaReg("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
	
	// => this regex subsume anu number with standard notation
	// => from simple ints all the way to scientific numbers


	// PART B)

	std::string s1{ "10" };
	std::string s2{ "3.14" };
	std::string s3{ "3.14e7" };
	std::string s4{ "-3.14E-3" };
	std::string s5{ "abc" };
	std::string s6{ "E-6"};

	std::cout << std::boolalpha;

	std::cout << s1 << ": " << std::regex_match(s1, ecmaReg) << std::endl;
	std::cout << s2 << ": " << std::regex_match(s2, ecmaReg) << std::endl;
	std::cout << s3 << ": " << std::regex_match(s3, ecmaReg) << std::endl;
	std::cout << s4 << ": " << std::regex_match(s4, ecmaReg) << std::endl;
	std::cout << s5 << ": " << std::regex_match(s5, ecmaReg) << std::endl;
	std::cout << s6 << ": " << std::regex_match(s6, ecmaReg) << std::endl;

	//=> any number works

	// PART C)

	str2double(s1);
	str2double(s2);
	str2double(s3);
	str2double(s4);
	str2double(s5);
	str2double(s6);
	// => works as expected

}