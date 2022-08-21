// Level6_Section12_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Counter.h"

#include <iostream>

int main() {

	Counter* counter1{ new Counter() };
	Counter* counter2{ new Counter() };
	counter1->AddObserver(counter2);

	counter1->Update(counter1);
	counter1->Update(counter1);
	//=> both are incremented

	counter1->DeleteObserver(counter2);
	
	counter1->Update(counter1);
	counter1->Update(counter1);
	//=> only counter 1 is now
}