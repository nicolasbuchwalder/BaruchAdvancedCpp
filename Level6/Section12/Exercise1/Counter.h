// Counter.h: this file contains the class to change value of observers, derived from Observabke
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include "Observable.h"
#include "Observer.h"

#include <iostream>
class Counter :
    public Observable, public Observer
{
private:
    double _count;

public:

    // default constructor
    Counter() :
        _count{ 0 } {};

    // function that returns the current counter value
    double GetCounter() { return _count; };

    // function that increases the coounter value, prints counter and calls notify on the observers
    void Update(Observable* observer) { 
        ++_count;  
        std::cout << "counter " << this << " is at : " << GetCounter() << std::endl;
        NotifyObservers(); };

};

