// Comparator.h: This file contains the class for comparing command elements
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

class Command;

class Comparator
{
public:
	bool operator()(Command l, Command r) {
		return l.priority() > r.priority();
	};

};

