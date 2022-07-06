// Base.h: This file contains the base class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <iostream>

// GIVEN CODE
class Base
{
private:
public:
    Base() { }
    virtual void print() const = 0;
protected:
    virtual ~Base() { std::cout << "Base destructor\n\n"; }
};

