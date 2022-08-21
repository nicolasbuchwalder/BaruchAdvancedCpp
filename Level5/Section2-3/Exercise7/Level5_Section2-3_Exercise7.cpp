// Level5_Section2-3_Exercise7.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <regex>
#include <iostream>

int main() {

	std::string text("Quick brown fox");
	std::regex vowels("a|e|i|o|u");

	// replacing vowels with a star
	std::string noVowels = std::regex_replace(text, vowels, "*");

	std::cout << noVowels << std::endl;
}