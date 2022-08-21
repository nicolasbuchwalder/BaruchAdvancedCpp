// Subject.h: this file contains the class abstract subject that handles observers
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <list>
#include <memory>

// forward declaration 
class Observer;

class Subject
{
private:
	// list of observers
	std::list <Observer*> observers;

public:

	// virtual function to add an observer
	virtual void Attach(Observer* observer);

	// virtual function to remove an observer
	virtual void Detach(Observer* observer);

	// virtual function to notify observers
	virtual void Notify();
};

