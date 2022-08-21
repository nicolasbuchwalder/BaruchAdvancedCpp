// Observer.h: this file contains the abstract of classes that observe data
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <memory>
#include <iostream>

// forward decleration
class Subject;


class Observer
{
public:
	// pure virtual function to update to which subject the observer is assigned to
	virtual void Update(Subject* subject) = 0;

};


