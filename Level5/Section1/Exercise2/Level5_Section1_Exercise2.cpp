// Level5_Section1_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>

// PART B)

// function to check password
bool check_password(const std::string& s) {
	if (s.size() >= 8) {
		std::cout << "length bigger than 8" << std::endl;
		return false;
	}
	if (boost::all(s, boost::is_alnum())) {
		std::cout << "not alphanumeric" << std::endl;
		return false;
	}
	if (boost::all(s, !boost::is_lower())) {
		std::cout << "no upper case" << std::endl;
		return false;
	}
	if (boost::contains(s, "\*")) {
		std::cout << "no spaces" << std::endl;
		return false;
	}
	if (boost::contains(s, " ")) {
		std::cout << "no spaces" << std::endl;
		return false;
	}
	return true;
};

int main() {

	// PART A)

	std::string str1(" abd1 234");

	// all digits or letters
	std::cout << std::boolalpha << boost::all(str1, boost::is_alnum()) << std::endl;
	// digits but not letters
	std::cout << std::boolalpha << boost::all(str1, boost::is_digit()) << std::endl;
	// lower cases
	std::cout << std::boolalpha << boost::all(str1, boost::is_lower()) << std::endl;

	// PART B)

	std::string pwd("DanielDuffy1952");
	check_password(pwd);
	pwd ="DanielDuffy";
	check_password(pwd);
	pwd = "U19520829";
	check_password(pwd);
	pwd = "19520829U";
	check_password(pwd);

}