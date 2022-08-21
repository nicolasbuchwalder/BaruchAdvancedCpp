// Counter.h: this file contains the class to change value of observers
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Subject.h"

class Counter :
    public Subject
{
private:
    double _count;

public:

    // default constructor
    Counter() :
        _count{ 0 } {};

    // function that returns the current counter value
    double GetCounter() { return _count; };

    // function that increases the coounter value and calls notify on the observers
    void IncreaseCounter() { ++_count; Notify(); };

    // function that decreases the coounter value and calls notify on the observers
    void DecreaseCounter() { --_count; Notify(); };

};

