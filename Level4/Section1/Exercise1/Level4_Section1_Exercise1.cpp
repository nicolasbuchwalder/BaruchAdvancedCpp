// Level4_Section1_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Proposition.h"

#include <iostream>
#include <array>

int main() {
	bool truth{ true };
	Proposition A(true);
	Proposition B(false);

	// PART B)
	// testing all functions
	std::cout << std::boolalpha << (A == truth) << std::endl;	// equality
	std::cout << std::boolalpha << (A != truth) << std::endl;	// inequality
	std::cout << (A & B) << std::endl;						// and
	std::cout << (A | B) << std::endl;						// or
	std::cout << (A ^ B) << std::endl;						// xor
	std::cout << (!A) << std::endl;							// not
	std::cout << (A % B) << std::endl;						// conditionnal
	std::cout << (A %= B) << std::endl;						// biconditionnal
	B = truth;
	std::cout << B << std::endl;								// assignement
	std::cout << std::endl;
	//=> everything works

	// PART C)
	// checking De Morgan's Laws
	std::cout << "De Morgan Laws:" << std::endl;
	std::cout << std::boolalpha << (!(A | B) == (!A & !B)) << std::endl;
	std::cout << std::boolalpha << (!(A & B) == (!A | !B)) << std::endl;
	//=> they are verified

	// PART D)
	// checking Distributive Laws
	Proposition C(true);
	std::cout << "Distributive Laws:" << std::endl;
	std::cout << std::boolalpha << (A & (B | C) == ((A & B) | (A & C))) << std::endl;
	std::cout << std::boolalpha << (A | (B & C) == ((A | B) & (A | C))) << std::endl;
	//=> they are also verified

	// PART E)
	// array that contains true or false (for for loops below)
	std::array<Proposition, 2> truefalse{ Proposition(true), Proposition(false) };
	// iterating over three nested loops to get all values:
	for (auto A : truefalse) {
		for (auto B : truefalse) {
			for (auto C : truefalse) {
				std::cout << "Values: " << A << B << C << " LHS and RHS equal? " << ((A % (B % C)) == ((A & B) % C)) << std::endl;
			};
		};
	};
	//=> we notice that it is indeed a tautology
}
