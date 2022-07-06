// C2.h: Class that contains shared pointer with class C2
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include <memory>
#include <iostream>

class C2 {
private:
    std::shared_ptr<double> d;

public:
    C2(std::shared_ptr<double> value) : d(value) {}
    virtual ~C2() { std::cout << "C2 destructor" << std::endl; }
    void print() const { std::cout << "Value: " << *d << std::endl; }
};

