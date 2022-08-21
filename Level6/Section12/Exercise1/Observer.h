// Observer.h: this file contains the abstract class for observers, which will be inherited from derived Observebales
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "Observable.h"

class Observer
{
public:
	virtual void Update(Observable* observer) = 0;
};

