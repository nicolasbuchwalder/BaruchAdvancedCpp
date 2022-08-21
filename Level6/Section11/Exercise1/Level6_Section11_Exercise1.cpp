// Level6_Section11_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Counter.h"
#include "LongFormat.h"
#include "DoubleFormat.h"

#include <iostream>

int main() {

	// PART D)
	Counter* counter{ new Counter() };
	
	// PART L)
	
	LongFormat double_obs(counter);
	DoubleFormat long_obs(counter);

	counter->IncreaseCounter();
	counter->IncreaseCounter();
	counter->DecreaseCounter();
	counter->IncreaseCounter();
	// => works but as we are dealing with small integers, we do not see the difference between long and double formats
}