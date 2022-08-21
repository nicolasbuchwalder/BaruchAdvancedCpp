// Exception.h: This file contains the abstract class for the programs exceptions
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <exception>

class Exception :
	public std::exception
{
public:
	// pure virtual function to print what the derived exceptions are
	// format to match std::exception method
	virtual const char* what() const noexcept = 0;
};

