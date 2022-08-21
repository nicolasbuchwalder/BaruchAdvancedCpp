// Subject.cpp: this file contains the abstract class subject that handles observers
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Subject.h"
#include "Observer.h"

// virtual function to add an observer
void Subject::Attach(Observer* observer) {
	observers.push_back(observer);
}

// virtual function to remove an observer
void Subject::Detach(Observer* observer) {
	observers.remove(observer);
}

// virtual function to notify observers
void Subject::Notify() {
	for (auto observer : observers) {
		observer->Update(this);
	}
}
