// Derived.h: This file contains the base class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include "Base.h"

#include <iostream>

class Derived : public Base
{
private:
public:
    Derived() : Base() { }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
    void print() const { std::cout << "Print derived object" << std::endl; }
};

