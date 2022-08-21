// Observable.h: this file contains the class abstract subject that handles observers
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <list>

class Observable
{
protected:

	// list of depedent observables
	std::list<Observable*> _observers_list;

public:
	// function to add an observer (observable)
	virtual void AddObserver(Observable* observer);

	// function to remove an observer (observable)
	virtual void DeleteObserver(Observable* observer);

	// function to notify all depdendent observers (observable)
	virtual void NotifyObservers();

	// pure virtual function that each derived observable needs to have to print to the interface
	// also necessary to make the class abstract
	virtual void Update(Observable* observer) = 0;

};

