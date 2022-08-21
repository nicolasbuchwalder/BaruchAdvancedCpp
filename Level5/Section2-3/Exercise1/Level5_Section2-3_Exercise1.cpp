// Level5_Section2-3_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

int main() {

	std::cout << std::boolalpha;

	// PART A)

	boost::regex myReg("[a-z]*");
	boost::regex myReg2("[a-z]+");

	std::string s1("aza");
	std::string s2("1");
	std::string s3("b");
	std::string s4("ZZ TOP");

	std::cout << s1 << ", " << boost::regex_match(s1, myReg) << std::endl;
	// => true, myReg range is lower alpha from 0 to inf
	std::cout << s2 << ", " << boost::regex_match(s2, myReg) << std::endl;
	// => false, myReg range does not contain numbers
	std::cout << s3 << ", " << boost::regex_match(s3, myReg) << std::endl;
	// => true, myReg range is lower alpha from 0 to inf
	std::cout << s4 << ", " << boost::regex_match(s4, myReg) << std::endl;
	// => false, myReg does not contain upper alpha 

	std::cout << s1 << ", " << boost::regex_match(s1, myReg2) << std::endl;
	// => true, myReg2 range is lower alpha from 1 to inf
	std::cout << s2 << ", " << boost::regex_match(s2, myReg2) << std::endl;
	// => false, myReg2 range does not contain numbers
	std::cout << s3 << ", " << boost::regex_match(s3, myReg2) << std::endl;
	// => true, myReg2 range is lower alpha from 1 to inf
	std::cout << s4 << ", " << boost::regex_match(s4, myReg2) << std::endl;
	// => false, myReg does not contain upper alpha 

	// PART B)

	boost::regex myNumericReg("\\d{2}");
	std::string f("34");
	std::string s("345");

	std::cout << f << ", " << boost::regex_match(f, myNumericReg)<< std::endl;  
	// => true, myNumericRegdigits wants 2 digits
	std::cout << s << ", " << boost::regex_match(s, myNumericReg) << std::endl;
	// => false,  myNumericRegdigits wants 2 digits

	// PART C)

	boost::regex myAltReg("(new)|(delete)");
	std::string s4A("new");
	std::string s5("delete");
	std::string s6("malloc");

	std::cout << s4A << ", " << boost::regex_match(s4A, myAltReg) << std::endl;  
	// => true, "new" is one of the two options of myAltReg
	std::cout << s5 << ", " << boost::regex_match(s5, myAltReg) << std::endl;  
	// => true, "delete" is one of the two options of myAltReg
	std::cout << s6 << ", " << boost::regex_match(s6, myAltReg) << std::endl;
	// => false, "malloc" is not one of the two options of myAltReg


	// PART D)

	boost::regex myReg3("A*");
	boost::regex myReg4("A+");
	boost::regex myReg5("(\\d{2})");
	boost::regex myReg6("\\d{2, 4}");
	boost::regex myReg7("\\d{1,}");

	std::string testA("1");

	std::cout << testA << ", " << boost::regex_match(testA, myReg3) << std::endl;  
	// => false, 1 is not A
	std::cout << testA << ", " << boost::regex_match(testA, myReg4) << std::endl;
	// => false, 1 is not A
	std::cout << testA << ", " << boost::regex_match(testA, myReg5) << std::endl;
	// => false, myReg5 wants 2 digits
	std::cout << testA << ", " << boost::regex_match(testA, myReg6) << std::endl;
	// => false, myReg6 wants between 2 and 4 digits
	std::cout << testA << ", " << boost::regex_match(testA, myReg7) << std::endl;
	// => true, myReg7 wants between 1 or more digits

	// PART E)

	boost::regex rC("(\\w)*"); // Alphanumeric (word) A-Za-z0-9
	boost::regex rC1("(\\W)*"); // Not a word
	boost::regex rC2("[A-Za-z0-9_]*"); // Alphanumeric (word) A-Za-z0-9

	std::string sC1("abc");
	std::string sC2("A12678Z909za");

	std::cout << sC1 << ", " << boost::regex_match(sC1, rC) << std::endl;  
	// =>true, abc is alphanumeric
	std::cout << sC1 << ", " << boost::regex_match(sC1, rC1) << std::endl;  
	// => true, abs is not a word
	std::cout << sC1 << ", " << boost::regex_match(sC1, rC2) << std::endl;  
	// => true abc is alphanumeric
	std::cout << sC2 << ", " << boost::regex_match(sC2, rC) << std::endl;
	// => true, is alphanumeric
	std::cout << sC2 << ", " << boost::regex_match(sC2, rC1) << std::endl;
	// => true, is not a word
	std::cout << sC2 << ", " << boost::regex_match(sC2, rC2) << std::endl;
	// => true is alphanumeric






}