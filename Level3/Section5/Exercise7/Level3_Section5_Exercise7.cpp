// Level3_Section5_Exercise7.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <ratio>
#include <iostream>


int main() {

	// PART A)

	typedef std::ratio<1, 5> r1;
	std::cout << r1::num << "/" << r1::den << std::endl;
	typedef std::ratio<6, 7> r2;
	std::cout << r2::num << "/" << r2::den << std::endl;
	typedef std::ratio<13, 13> r3;
	std::cout << r3::num << "/" << r3::den << std::endl;
	// => works as expected, we notice also how the ratio is transformed into irreductible form

	// PART B)

	typedef std::ratio_add<r1, r2> sum;
	std::cout << sum::num << "/" << sum::den << std::endl;

	typedef std::ratio_subtract<r1, r2> difference;
	std::cout << difference::num << "/" << difference::den << std::endl;

	typedef std::ratio_multiply<r1, r2> product;
	std::cout << product::num << "/" << product::den << std::endl;

	typedef std::ratio_multiply<r1, r2> quotient;
	std::cout << quotient::num << "/" << quotient::den << std::endl;
	//=> expected results
}