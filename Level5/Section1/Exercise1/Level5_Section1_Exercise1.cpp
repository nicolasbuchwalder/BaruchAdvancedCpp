// Level5_Section1_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>

int main() {
	std::string s1{ "     Hello world!     " };
	std::string s2{ " 1.0.4:   Paragraph   " };
	std::string s3{ "-----This is a message:----" };
	std::string s4{ "password:353294328" };
	std::string s5{ "This is also a message/over" };

	// PART A)

	// trimming in place
	boost::trim(s1);
	std::cout << s1 << std::endl;

	// trimming copy
	auto s2_trimmed{ boost::trim_copy(s2) };
	std::cout << s2 << ", " << s2_trimmed << std::endl;

	// PART B)

	// trimming if char is -
	auto check = [](char c) {return c == '-'; };
	boost::trim_if(s3, check);
	std::cout << s3 << std::endl;
	
	// PART C)
	
	// starting with
	std::cout << std::boolalpha << boost::starts_with(s4, "password:") << std::endl;
	// ending with
	std::cout << std::boolalpha << boost::ends_with(s5, "/over") << std::endl;

	// PART D)

	// case sensitive
	std::cout << std::boolalpha << boost::contains(s1, "Hello") << std::endl;

	// case unsensitive
	std::cout << std::boolalpha << boost::icontains(s4, "PASSWORD") << std::endl;


}