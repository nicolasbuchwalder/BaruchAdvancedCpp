// Observable.cpp: this file contains the class abstract subject that handles observers
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Observable.h"

// function to add an observer (observable)
void Observable::AddObserver(Observable* observer) {
	_observers_list.push_back(observer);
}

// function to remove an observer (observable)
void Observable::DeleteObserver(Observable* observer) {
	_observers_list.remove(observer);
}

// function to notify all depdendent observers (observable)
void Observable::NotifyObservers() {
	for (auto observer : _observers_list) {
		observer->Update(this);
		observer->NotifyObservers();
	};
}