// Class.h: This file contains a standard Class for testing static functions in threads
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include <string>

void lprint(const std::string& s, int count);

class Class
{
public:
	static void StaticFunction() { lprint("static function", 3); };
	
};

