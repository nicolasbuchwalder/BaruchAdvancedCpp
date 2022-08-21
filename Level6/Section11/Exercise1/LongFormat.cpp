// LongFormat.cpp: this file is an observer that shows the value of the subject in long format
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "LongFormat.h"

#include "Counter.h"

// initialize with pointer
LongFormat::LongFormat(Counter* pt) :
    _counter{ pt } {
        _counter->Attach(this);
};


// override update method from abstract class
void LongFormat::Update(Subject* subject) {
    std::cout << "counter " << subject << " in long format : " << static_cast<long>(_counter->GetCounter()) << std::endl;
}
