// Level6_Section9_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Stack.h"

#include <iostream>

int main() {

	Stack stack(3);
	try {
		stack.Pop();
	}
	catch (std::runtime_error& err) {
		std::cerr << err.what() << std::endl;
	}
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	

	try {
		stack.Push(4);
	}
	catch (std::runtime_error& err) {
		std::cerr << err.what() << std::endl;
	}
	//=> we cannot see the states but it seems to work as expected
	


}